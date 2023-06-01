#!/bin/bash

mkdir -p build || exit $?
conan install . --output-folder=build || exit $?
cd build || exit $?
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release -GNinja || exit $?
ninja || exit $?

./$1/$1
