#!/bin/bash

export CC=clang-15 || exit $?
export CXX=clang++-15 || exit $?

mkdir -p build || exit $?
cd build || exit $?
conan install .. --build=missing --output-folder=build -s build_type=$1 || exit $?
cmake .. \
    -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake \
    -DCMAKE_BUILD_TYPE=$1 \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
    -GNinja \
    || exit $?
cp compile_commands.json .. || exit $?
ninja $2 || exit $?

./$2/$2 || exit $?
