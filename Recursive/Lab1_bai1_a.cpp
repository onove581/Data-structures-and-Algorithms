#include <stdio.h>
int Fibonacci(int n)
{
    int a = 1, b = 1;
    if (n == 1 || n == 2)
        return 1;
    int i = 3, s;
    while (i <= n)
    {
        s = a + b;
        a = b;
       b = s;
        i++;
    }
    return s;
}
int main()
{
    int n;
    printf("nhap so Fibonacci n ma ban can tim: ");
    scanf("%d", &n);
    printf("So Fibonacci thu %d la: %d", n, Fibonacci(n));
    return 1;
}
