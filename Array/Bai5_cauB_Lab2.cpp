#include <stdio.h>
#include <stdlib.h>
  
void nhapContro(int *(*a), int *n) {
    int i;
 
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", n); 
    *a = (int *) malloc ((*n) * sizeof(int));
    
    for (i = 0; i < *n; i++) {
        printf("Nhap a[%d] = ", i);
        scanf("%d", (*a + i));
    }
}
  
void xuatMang(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf ("%d \t", a[i]);
    }
}
void tongchiahetcho5(int *a,int n)
{
	int sum=0;
	for (int i = 0; i < n; i++) {
        if (a[i]%5==0)
        sum+=a[i];
    }
    printf("\nTong chia het cho 5: %d",sum);
}
int main() {
    int *a, n;
     
    nhapContro(&a, &n);
    printf("Xuat mang:\n");
    xuatMang(a, n);
      tongchiahetcho5(a,n);
    return 0;
}
