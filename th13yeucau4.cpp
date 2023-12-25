#include <stdio.h>

void nhapMang(int a[], int n, int i);
void xuatMang(int a[], int n, int i);

int main()
{
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    int a[n];
    printf("Nhap cac phan tu cua mang:\n");
    nhapMang(a, n, 0);
    printf("Mang vua nhap:\n");
    xuatMang(a, n, 0);

    return 0;
}

void nhapMang(int a[], int n, int i)
{
    if (i == n)
        return;

    printf("a[%d] = ", i);
    scanf("%d", &a[i]);

    nhapMang(a, n, i + 1);
}

void xuatMang(int a[], int n, int i)
{
    if (i == n)
        return;

    printf("%d ", a[i]);

    xuatMang(a, n, i + 1);
}

