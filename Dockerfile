FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    g++ \
    gcc \
    gdb \
    make \
    python3 \
    ed \
    git \
    gcc-mips-linux-gnu \
    binutils-mips-linux-gnu \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /nachos

COPY . /nachos

RUN make -C code clean && make -C code

CMD ["python3", "code/test_runner.py", "--verbose"]
