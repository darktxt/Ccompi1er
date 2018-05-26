# Ccompiler

### 已实现
 
```
inline float test()

{

	int a=2,b=3;

	a = a > 1+2*3/(b+1);

	a = a>1 ? b+2 :b;

}

void main(int x,int y)

{

	int b;

}
```
### 另，已实现 if while for
---

编译命令

`bison -d -o compiler.cpp  compiler.y`

`flex -o mylex.cpp compiler.l`

`g++ -std=c++11 -o compiler compiler.cpp mylex.cpp main.cpp`
