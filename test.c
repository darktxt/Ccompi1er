int s(int x){
	int y = x + 1;
	print(x);
	print(y);
	return x*y;
}


void main()
{
	int a = 5;
	int c = s(a);
	print(c);
}