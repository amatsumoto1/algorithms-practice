#!/bin/bash

build_dir=../../build


if [ -d "$(build_dir)" ]
then
	rm -r "$(build_dir)/*"
else
	cmake -E make_directory $build_dir
fi

pushd $build_dir

cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug
ctest -C Debug --verbose

popd