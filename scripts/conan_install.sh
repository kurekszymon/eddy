#!/bin/zsh
conan install conanfile.txt \
    --output-folder=conan \
    --build=missing \
    -s compiler.cppstd=20 \
    -c tools.cmake.cmaketoolchain:generator=Ninja