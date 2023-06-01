#!/bin/bash

mkdir -p build || exit $?
conan install . --output-folder=build || exit $?
cd build || exit $?
export CC=clang-15 || exit $?
export CXX=clang++-15 || exit $?
cmake .. \
    -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
    -GNinja \
    || exit $?
cp compile_commands.json .. || exit $?
ninja $1 || exit $?

./$1/$1
