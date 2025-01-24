# Use Ubuntu 22.04 as the base image
FROM ubuntu:22.04

# Suppress debconf interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# Switch to root user for system-level installations
USER root

# Create a new user to work in
RUN rm /bin/sh && ln -s /bin/bash /bin/sh
RUN useradd -ms /bin/bash fuzz

# Update and install basic utilities
RUN apt-get update && apt-get install -y \
    software-properties-common \
    build-essential \
    apt-utils \
    wget \
    curl \
    git \
    vim \
    nano \
    zip \
    unzip \
    lsb-release \
    zlib1g \
    zlib1g-dev \
    libssl-dev

# Add GCC repository and install GCC 11
RUN add-apt-repository ppa:ubuntu-toolchain-r/test -y && \
    apt-get update && \
    apt-get install -y gcc-11 g++-11 m4 cmake ninja-build

# Install Clang 17 + llvm-17-dev
RUN wget https://apt.llvm.org/llvm.sh && \
    chmod +x llvm.sh && \
    ./llvm.sh 17
RUN apt-get install -y llvm-17-dev
ENV LLVM_CONFIG=/usr/bin/llvm-config-17

# Set GCC 11 as the default compiler
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 100 \
    --slave /usr/bin/g++ g++ /usr/bin/g++-11

# Create symlinks for clang and clang++
RUN update-alternatives --install /usr/bin/clang clang /usr/lib/llvm-17/bin/clang 100 && \
    update-alternatives --install /usr/bin/clang++ clang++ /usr/lib/llvm-17/bin/clang++ 100

# Install pre-requirements for AFL++
RUN apt-get install -y python3-dev python3-apt python3-distutils
RUN apt-get install -y gcc-11-plugin-dev

# Switch to the fuzz user
USER fuzz

# Set working directory
WORKDIR /home/fuzz

# Build and install AFL++
RUN git clone https://github.com/AFLplusplus/AFLplusplus.git
WORKDIR /home/fuzz/AFLplusplus
RUN git checkout f596a297c4de6a5e1a6fb9fbb3b4e18124a24f58
RUN AFL_USE_ASAN=0 make
USER root
RUN make install
USER fuzz

# Build Clang with AFL++ instrumentation
WORKDIR /home/fuzz/
RUN git clone https://github.com/llvm/llvm-project.git
WORKDIR /home/fuzz/llvm-project
RUN git checkout release/17.x

# Configure with AFL for ARM systems
WORKDIR /home/fuzz/
RUN mkdir build
WORKDIR /home/fuzz/build
RUN AFL_USE_ASAN=0 cmake -G Ninja -Wall ../llvm-project/llvm/ \
    -DLLVM_ENABLE_PROJECTS="clang" \
    -DCMAKE_BUILD_TYPE="Release" \
    -DCMAKE_C_COMPILER=/usr/local/bin/afl-cc \
    -DCMAKE_CXX_COMPILER=/usr/local/bin/afl-c++ \
    -DCMAKE_LINKER=/usr/local/bin/afl-cc \
    -DBUILD_SHARED_LIBS=OFF \
    -DLLVM_TARGETS_TO_BUILD="ARM;AArch64" \
    -DLLVM_BUILD_DOCS="OFF" \
    -DLLVM_BUILD_EXAMPLES="OFF" \
    -DCMAKE_EXE_LINKER_FLAGS="-L/usr/lib/arm-linux-gnueabihf -L/usr/lib/aarch64-linux-gnu"


# Build
RUN AFL_USE_ASAN=0 ninja -j4 -l2

# Display versions of installed tools (optional for debugging)
RUN gcc --version && g++ --version && clang --version && \
    cmake --version && ninja --version
