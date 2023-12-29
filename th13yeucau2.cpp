#include <stdio.h>

int tinhgiaithua(int n)
{
    if (n == 0)
        return 1;
    else
        return n * tinhgiaithua(n - 1);
}
int main()
{
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);
    printf("Giai thua cua %d la: %d\n", n, tinhgiaithua(n));
    return 0;
}

