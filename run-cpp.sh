#!/bin/bash

source venv/bin/activate

export CC=clang-16 || exit $?
export CXX=clang++-16 || exit $?

BUILD_TYPE=${2:-Debug}

mkdir -p build || exit $?
cd build || exit $?
conan install .. --build=missing --output-folder=build -s build_type=$BUILD_TYPE || exit $?
cmake .. \
    -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake \
    -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
    -GNinja \
    || exit $?
cp compile_commands.json .. || exit $?
ninja $1 || exit $?

./$1/$1 || exit $?
