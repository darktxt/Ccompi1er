#! /bin/bash
bison -d -o compiler.cpp  compiler.y
flex -o mylex.cpp compiler.l
# g++ -std=c++11 -o compiler compiler.cpp mylex.cpp main.cpp
clang++ -std=c++11 -g main.cpp compiler.cpp mylex.cpp `llvm-config --cxxflags --ldflags --system-libs --libs all` -o toy