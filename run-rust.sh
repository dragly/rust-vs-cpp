#!/bin/bash

BUILD_TYPE=${2:-Debug}

if [ $BUILD_TYPE = Debug ]
then
    BUILD_FLAG=
else
    BUILD_FLAG=--release
fi

cargo run $BUILD_FLAG --bin $1
