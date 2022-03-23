#include<stdio.h>
#include<conio.h>

void indayFibonacci(int n){  
    static int n1=0,n2=1,n3;  
    if(n>0){  
         n3 = n1 + n2;  
         n1 = n2;  
         n2 = n3;  
         printf("%d ",n3);  
         indayFibonacci(n-1);  
    }  
}  
int main(){  
    int n;  
    
    printf("Nhap n: ");  
    scanf("%d",&n);  
    printf("n so Fibo la:\n\n");  
    printf("%d %d ",0,1);  
    indayFibonacci(n-2);  

}  
