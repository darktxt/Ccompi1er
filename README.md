# Ccompiler
---

编译命令

`bison -d -o compiler.cpp  compiler.y`

`flex -o mylex.cpp compiler.l`

`g++ -std=c++11 -o compiler compiler.cpp mylex.cpp main.cpp`