
int test(){
	return 2;
}

void main()
{
	int c;
	int b;
	int d;
	d = read();
	for(c=0;c<d;c=c+1){
		b = b + test();
	}
	print(b);
}
