#include<stdio.h>

int C(int k, int n) {
    if (k == 0 || k == n) return 1;
    if (k == 1) return n;
    return C(k - 1, n - 1) + C(k, n - 1);
}
int main(){
    int n, k;
    printf("nhap n:");
    scanf("%d",&n);
    
   printf("nhap k:");
    scanf("%d",&k);
     printf("to hop la %d",C(n,k));
    
    return 0;
}
