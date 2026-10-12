# Lab 3: 虚拟内存与页面置换 (Virtual Memory & Paging)

---

## 1. 实验目标与理论背景

当用户程序的内存需求超过物理内存容量时，操作系统通过**虚拟内存（Virtual Memory）**技术为每个程序提供一个比物理内存大得多的私有连续虚拟地址空间。

Nachos 3.4 支持现代 RISC 处理器的**软件加载式 TLB（Software-Loaded TLB）**架构：
- 硬件只维护小容量高速缓存（16 项 TLB）。
- 当 TLB 缺失（TLB Miss）时，硬件不自动遍历多级页表，而是抛出 `PageFaultException`，由**内核软件负责将缺失页调入 TLB**。

完成本实验后，你将能够：
1. 深入理解 TLB（快表）在地址转换流水线中的加速角色。
2. 掌握软件处理 TLB 缺失与缺页异常的完整闭环。
3. 掌握页面置换算法的设计与评估（FIFO、LRU、Clock 时钟算法）。
4. 实现按需调页（Demand Paging / Lazy Loading）与交换文件（Swap Space）。

---

## 2. 虚拟内存工作流程

```mermaid
flowchart TD
    Access["CPU 访问虚拟地址 (VA)"] --> TLBLookup{"TLB 查找匹配项"}
    TLBLookup -->|命中| CheckRO{"是否写只读页?"}
    CheckRO -->|是| ROException["抛出 ReadOnlyException"]
    CheckRO -->|否| AccessMem["物理内存命中 (设置 use/dirty 位)"]

    TLBLookup -->|未命中 (TLB Fault)| Trap["触发 PageFaultException"]
    Trap --> CheckInMem{"该虚页是否在物理内存中?"}
    CheckInMem -->|在内存中 (仅TLB缺失)| ReloadTLB["更新并填入 TLB (替换旧 TLB 项)"]
    ReloadTLB --> Resume["重新执行访存指令"]

    CheckInMem -->|不在内存中 (真正缺页)| FindFrame{"物理内存是否有空闲页框?"}
    FindFrame -->|有| LoadPage["从可执行文件/Swap 载入物理页框"]
    FindFrame -->|无 (内存满)| Victim["页面置换算法 (FIFO/Clock/LRU) 选择牺牲页"]
    Victim --> CheckDirty{"牺牲页 dirty 位是否为 1?"}
    CheckDirty -->|是| WriteSwap["写回 Swap 交换区"]
    CheckDirty -->|否| Discard["直接作废映射"]
    WriteSwap --> LoadPage
    Discard --> LoadPage
    LoadPage --> UpdatePT["更新页表 TranslationEntry"]
    UpdatePT --> ReloadTLB
```

---

## 3. 实验任务清单

### 任务 1：TLB 缺失充填处理程序 (TLB Miss Handler)

在 `code/vm/` 模式下（编译时带有 `-DUSE_TLB`），`machine->tlb` 生效，`machine->pageTable` 为 `nullptr`。

1. 在 `code/userprog/exception.cc` 中捕获 `PageFaultException`：
   - 从 `machine->ReadRegister(BadVAddrReg)` 读取触发异常的虚拟地址。
   - 计算虚拟页号：`vpn = badVAddr / PageSize`。
2. 从当前进程完整的后备页表（Backup Page Table）中找到对应的 `TranslationEntry`。
3. 选择一个 TLB 槽位进行充填：
   - 先填入无效（`valid == false`）的槽位。
   - 若 16 个 TLB 项全满，使用 FIFO 或随机算法选择一个槽位踢出，并将新项载入。
   - **注意**：踢出旧项前，必须将 TLB 项中的 `dirty` 和 `use` 位写回进程的后备页表中！

### 任务 2：实现页面置换算法 (Page Replacement)

设计模块化的页面置换策略接口：
```cpp
class PageReplacementPolicy {
  public:
    virtual ~PageReplacementPolicy() = default;
    virtual void RecordAccess(int physicalPage) = 0;
    virtual int SelectVictimPage() = 0;
};
```
实现以下经典算法并进行缺页率（Page Fault Rate）比对：
1. **FIFO（先进先出置换算法）**：维护物理页分配的队列，最先分配的页最先被换出。
2. **Clock（时钟算法 / 二次机会算法）**：
   - 维护一个环形指针遍历物理页。
   - 检查 `use` 位：若为 1 则清 0 并跳过；若为 0 则选为牺牲页。
3. **LRU（最近最少使用算法）**：通过时间戳或链表记录页面访问时序，选出最久未使用的页。

### 任务 3：交换区支持 (Swap Space Management)

为了支持虚拟内存总大小远大于物理内存大小：
1. 创建虚拟交换磁盘文件：
   ```cpp
   fileSystem->Create("SWAP_DISK", SwapFileSize);
   OpenFile *swapFile = fileSystem->Open("SWAP_DISK");
   ```
2. **换出（Page Out）**：
   - 当某个物理页被选为牺牲页且被修改（`dirty == true`）时，将其写入 Swap 对应的扇区中。
   - 在后备页表中标记该页不在内存（`valid = false`），并记录其 Swap 扇区位置。
3. **换入（Page In）**：
   - 缺页异常发生时，若该页曾被保存在 Swap 中，从 Swap 读取其内容恢复到物理页框中。

---

## 4. 调试与自动化测试

```bash
# 进入 vm 目标调试
./vm/nachos -d a

# 运行自动化测试套件
./test_runner.py --filter vm --verbose
```
确保包含 TLB 的虚拟内存内核模拟初始化与停机全部通过。
