#!/bin/bash
# build
rm -rf build
mkdir build
cd build
cmake ..
make 
#run
LD_LIBRARY_PATH=../lib
