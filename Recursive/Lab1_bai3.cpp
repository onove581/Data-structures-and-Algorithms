#include<stdio.h>
int tong(int n)
{
	if(n==0) return 0;
	return n+tong(n-2);
}
int main()
{
	int d;
	
	printf("Nhap so n: ");
	scanf("%d",&d);
	printf("tong cac so chan tu 1 den n la: %d",tong(d));
}

