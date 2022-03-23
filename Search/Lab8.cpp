#include<stdio.h>

int LinearSearch(int x,int a[],int n){
for(int i=0; i<n; i++)
if(x==a[i])
return i;
return -1;
}
int BinSearch(int x,int a[],int n){
int i=0,j=n-1,c;
while(i <= j ) {
c=(i+j)/2;
if (x==a[c]) return c;
else if (x<a[c]) j=c-1;
else i=c+1;
}
return -1;
}
int main()
{
	
 int a[50],n, x;
 printf("Nhap vao so phan tu cua mang:");
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 {
 printf("Nhap mang[%d]: ",i);
 scanf("%d",&a[i]);
 }
 printf("Nhap vao so phan tu muon tim:");
 scanf("%d",&x);
 printf("\n==TIM KIEM TUAN TU ");
printf("\nVi tri Phan tu muon tim kiem theo tuan tu la %d",LinearSearch(x,a,n));
printf("\n===TIM KIEM NHI PHAN");
printf("\nVi tri Phan tu muon tim kiem theo nhi phan la %d",BinSearch(x,a,n));
}
