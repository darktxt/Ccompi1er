
void main()
{
	int c;
	int t;
	int d;
	d = read();
	int a0 = 1;
	int a1 = 1;
	for(c=0;c<d;c=c+1){
		if(c == 0){
			print(1);
			continue;
		}
		if(c == 1){
			print(1);
			continue;
		}
		t = a0+a1;
		a0 = a1;
		a1 = t;
		print(a1);
	}
}
