#include <stdio.h>
 
 
void NhapMaTran(float a[][100], int m, int n)
{
   for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
      {
         printf("A[%d][%d] = ", i, j);
         scanf("%f", &a[i][j]);
      }
}
 
void XuatMaTran(float a[][100], int m, int n)
{
   for(int i = 0; i < m; i++)
   {
      for(int j = 0; j < n; j++)
         printf("%f\t", a[i][j]);
      printf("\n");
   }
}
 float TongCacSo(float a[][100], int m, int n)
{
   float sum = 0;
   for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
         
            sum += a[i][j];
   return sum;
}
 double TichCacSo(float a[][100], int m, int n)
{
   double sum = 1;
   for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
         
            sum =sum* a[i][j];
   return sum;
}
int main(){
    float a[100][100];
    int m,n;
    do{
	
    printf("\nnhap so hang n = "); scanf("%d",&n);
    printf("\nnhap so cot m = "); scanf("%d",&m);
    
    }while(m<0 &&n<0);
    
    printf("\nnhap vao ma tran moi phan tu la mot so thuc:\n");
    NhapMaTran(a, m , n);
    XuatMaTran(a, m, n);
   
    printf("Tong cac So %f\n",TongCacSo(a,m,n));
    printf("Tich cac So %lf",TichCacSo(a,m,n));
}
 
