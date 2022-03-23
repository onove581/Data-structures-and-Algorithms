#include<conio.h>
#include<stdio.h>
int csc(int n,int a,int r)
{
      if (n==1) return a;
      return(r+csc(n-1,a,r));
}
int main()
{
      int n, a, r, i;
      printf("nhap so hang dau a= "); scanf("%d",&a);
      printf("nhap cong sai r= "); scanf("%d",&r);
      printf("nhap so luong cac phan tu can xuat n= ");
      scanf("%d",&n);
      if (n<=0) printf("so luong cac phan tu khong hop le");
      for(i=1;i<=n;i++)
            printf("\n tri thu %2d cua csc= %5d",i,csc(i,a,r));
      
}
