# Ccompiler

### 已实现
 
```
inline float test()

{

	int a=2,b=3;

	a = 1;

}

void main(int x,int y)

{

	int b;

}
```
---

编译命令

`bison -d -o compiler.cpp  compiler.y`

`flex -o mylex.cpp compiler.l`

`g++ -std=c++11 -o compiler compiler.cpp mylex.cpp main.cpp`
