#!/bin/bash

sudo apt update

# install apt packages
sudo apt install ninja-build || exit $?

# setup a venv and install conan
python -m venv venv || exit $?
source venv/bin/activate
python -m pip install conan || exit $?

# Install clang 15
pushd /tmp || exit $?
wget https://apt.llvm.org/llvm.sh  || exit $?
chmod +x llvm.sh  || exit $?
sudo ./llvm.sh 15  || exit $?
rm llvm.sh || exit $?
popd || exit $?

# Install Rust
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

conan profile detect