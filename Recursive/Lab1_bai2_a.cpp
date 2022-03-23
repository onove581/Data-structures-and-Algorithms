#include<stdio.h>
long long gt(int n)
{
	if(n==0) return 1;
	return n * gt(n - 1);
}
int main()
{
	int n;
	printf("nhap so :");
	scanf("%d",&n);
	//gt(n);
	printf("giai thua cua %d la %lld",n,gt(n));
}
