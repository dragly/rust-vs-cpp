#!/bin/bash

if [ "$EUID" == 0 ]; then
    apt update
    apt install sudo
fi

sudo apt update

# install apt packages
sudo apt install --assume-yes \
    lsb-release \
    software-properties-common \
    curl \
    gpg \
    ninja-build \
    python-is-python3 \
    python3 \
    python3-venv \
    wget \
    cmake \
    || exit $?

# setup a venv and install conan
python -m venv venv || exit $?
source venv/bin/activate
python -m pip install conan || exit $?

# Install clang 16
pushd /tmp || exit $?
wget https://apt.llvm.org/llvm.sh  || exit $?
chmod +x llvm.sh  || exit $?
sudo ./llvm.sh 16  || exit $?
rm llvm.sh || exit $?
popd || exit $?

# Install Rust
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh || exit $?

export CC=clang-16 || exit $?
export CXX=clang++-16 || exit $?
conan profile detect --force || exit $?
