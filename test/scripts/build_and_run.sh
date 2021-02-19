#!/bin/bash

BUILD_DIR=../../build


if [ -d "$BUILD_DIR" ]
then
	rm -rf $BUILD_DIR/*
else
	cmake -E make_directory $BUILD_DIR
fi

pushd $BUILD_DIR

cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug
ctest -C Debug --verbose

popd