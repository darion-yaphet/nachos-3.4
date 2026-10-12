FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Install base development tools and MIPS cross-compilation toolchain
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    g++ \
    gcc \
    clang \
    gdb \
    make \
    python3 \
    python3-pip \
    ed \
    csh \
    tcsh \
    git \
    curl \
    ca-certificates \
    gcc-mips-linux-gnu \
    binutils-mips-linux-gnu \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

CMD ["/bin/bash"]
