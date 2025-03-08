#!/bin/zsh
cmake -G Ninja --preset cmake-release
cmake --build conan
