int s1(int x){
	int y = x + 1;
	int z = x - 1;
	return y*z;
}


void main()
{
	int a = read();
	int c = s(s(3));
	print(c);
}