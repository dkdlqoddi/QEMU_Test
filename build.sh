#!/bin/sh

python	clean_cmake.py
python	make_cmake.py
cmake .
cmake --build .