# Nachos 3.4 (Modern C++17 Edition)

![CI](https://img.shields.io/badge/CI-GitHub%20Actions-brightgreen.svg)
![C++17](https://img.shields.io/badge/language-C%2B%2B17-blue.svg)
![Platform](https://img.shields.io/badge/platform-macOS%20ARM64%20%7C%20Linux%20x86__64-brightgreen.svg)
![Tests](https://img.shields.io/badge/tests-100%25%20passing-success.svg)

> 🎓 **Nachos（Not Another Completely Heuristic Operating System）** 是由加州大学伯克利分校（UC Berkeley）开发的经典操作系统教学软件。本项目经过全方位的**现代 C++17 工业级重构与教学基础设施升级**，为现代操作系统课程提供安全、健壮、易调试的高质量教学与实验基座。

---

## 🌟 核心特性与现代改进

- ⚡ **现代 C++17 架构与 RAII 内存安全**：
  - 全面引入 `std::unique_ptr`，实现锁、线程队列、文件描述符、地址空间页表的自动生命周期管理。
  - 引入 `LockGuard` 临界区作用域守卫，消除异常退出与提前返回造成的死锁隐患。
  - 核心参数与常量全面 `constexpr` 替换原生宏，提供严格编译期类型安全。
- 🛡️ **原生 Bug 修复与未定义行为 (UB) 消除**：
  - 修复 MIPS 模拟器原生 `OP_OR` 操作数笔误（`rs | rs` 纠正为 `rs | rt`）。
  - 使用 `std::memcpy` 重构内存访问，根除 ARM64/x86 架构下的指针类型双重泛型 punning 与未对齐访问 UB。
  - 消除 `coff2noff` 文件描述符检查逻辑错误与堆内存泄露。
- 🔍 **教学级并发锁滥用与死锁主动拦截**：
  - 运行时主动检测**自我死锁（Self-Deadlock）**、**非持有者越权释放锁（Lock Misuse）**、**持锁时异常析构**以及**条件变量未持锁调用**。
- 🎨 **现代上下文感知结构化日志**：
  - 支持 `LOG_INFO`, `LOG_WARN`, `LOG_ERROR`, `LOG_DEBUG` 宏，自动携带当前系统时钟周期（`Tick`）与正在执行的线程名。
  - 终端自适应 ANSI 彩色高亮输出，大幅降低多线程时序竞争排错难度。
- 🧪 **一键自动化测试套件与 CI 支持**：
  - 内置 Python 自动化测试脚本 [`code/test_runner.py`](code/test_runner.py)，一键覆盖并发调度、文件系统、用户态停机与虚拟内存。
- 🍎 **现代平台原生支持**：
  - 基于 POSIX `ucontext` 原生适配 Apple Silicon (macOS ARM64) 与 Linux (x86_64)。

---

## 🚀 快速上手

### 1. 环境准备与编译
本项目仅依赖现代 C++ 编译器（支持 C++17 的 GCC 或 Clang）与 GNU Make：

```bash
# 编译 Nachos 所有实验目标 (threads, userprog, vm, filesys, network)
make -C code clean
make -C code
```

### 2. 运行自动化测试套件
```bash
# 一键运行全部实验的自动化回归评测
./code/test_runner.py
```
测试覆盖常规并发、随机调度、Join 误用、链表移动所有权、用户内存边界、
文件系统边界和网络自投递。每个用例在独立临时目录运行，避免覆盖工作目录中的
`DISK`；没有匹配测试的筛选会返回非零退出码。

```bash
# 仅运行用户内存边界测试
python3 code/test_runner.py --filter memory_boundaries --verbose
```

### 3. 运行单个实验模块
```bash
# 运行内核线程并发测试
./code/threads/nachos

# 启用结构化彩色日志追踪线程调度 (-d t)
./code/threads/nachos -d t

# 格式化虚拟磁盘并列出文件系统元数据
./code/filesys/nachos -f -D
```

### 4. 🐳 容器化一键开发（VS Code DevContainer / Docker）
免去手动配置本地编译器的麻烦，开箱即用：
- **VS Code DevContainer**：
  在 VS Code 中安装 `Remote - Containers` 插件后，在项目窗口选择 **"Reopen in Container"**，自动加载已预装 GCC、Clang、GDB 与 MIPS 交叉编译工具链的 Ubuntu 22.04 容器。
- **原生 Docker 运行**：
  ```bash
  docker build -t nachos .
  docker run --rm -it nachos
  ```

---

## 📖 完整实验手册与教学指南

项目配备了详尽的 Markdown 现代实验指导手册与架构解析：

- 🏛️ [**系统架构与设计全景 (ARCHITECTURE.md)**](docs/ARCHITECTURE.md)：双层执行模型、MIPS 虚拟机与中断驱动时钟剖析。
- 🧵 [**Lab 1: 线程管理与并发同步**](docs/labs/lab1_threads.md)：线程调度、互斥锁、Mesa 条件变量与读写锁。
- 🖥️ [**Lab 2: 多道程序设计与系统调用**](docs/labs/lab2_userprog.md)：MIPS ABI 系统调用分发、安全用户内存拷贝与页框位图分配。
- 💾 [**Lab 3: 虚拟内存与页面置换**](docs/labs/lab3_vm.md)：TLB 缺失充填、FIFO/Clock/LRU 页面置换算法与 Swap 交换区。
- 📁 [**Lab 4: 文件系统扩展与目录树**](docs/labs/lab4_filesys.md)：突破 3.75KB 限制、一级/二级间接索引块与层次目录树。
- 🌐 [**Lab 5: 网络通信与可靠传输协议**](docs/labs/lab5_network.md)：邮局系统、停等协议与滑动窗口可靠传输。

---

## 📂 项目目录结构

```text
nachos-3.4/
├── docs/                     # 现代教学实验文档与架构指南
│   ├── ARCHITECTURE.md       # 系统架构全景指南
│   ├── README.md             # 实验手册索引中心
│   └── labs/                 # Lab 1 ~ Lab 5 实验指导书
├── code/                     # Nachos 内核核心源码
│   ├── threads/              # 线程管理、调度器、同步原语
│   ├── userprog/             # 用户程序加载器、系统调用异常分发
│   ├── vm/                   # 虚拟内存与 TLB 扩展
│   ├── filesys/              # 模拟物理磁盘、文件头、目录管理
│   ├── network/              # 网络数据报与邮局服务
│   ├── machine/              # MIPS 模拟虚拟机与硬件抽象层
│   ├── bin/                  # NOFF 可执行文件转换工具
│   └── test_runner.py        # 自动化评测与测试运行器
├── COPYRIGHT                 # 原作版权声明 (UC Berkeley)
└── README                    # 1993 原版发布说明存档
```

---

## 📜 版权与致敬

- 原作者：Tom Anderson 等人，加州大学伯克利分校（UC Berkeley）。
- 详见 [`COPYRIGHT`](COPYRIGHT) 文件。
