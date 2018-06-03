#! /bin/bash
bison -d -o compiler.cpp  compiler.y
flex -o mylex.cpp compiler.l
clang++ -std=c++11 -g main.cpp compiler.cpp mylex.cpp CodeGen.cpp `llvm-config --cxxflags --ldflags --system-libs --libs all` -o toy
./toy
clang++ output.o
./a.out

# g++ -std=c++11 -o compiler compiler.cpp mylex.cpp main.cpp 
# ./compiler > ./MIPS/intercode.txt
# echo "--------------AST代码----------------"
# cat ./MIPS/intercode.txt
# python3 ./MIPS/MIPS.py >> 2
# echo ""
# echo "--------------目标代码----------------"
# cat ./MIPS/objectcode.asm
# echo ""
# cat ./ErrorLog.txt
