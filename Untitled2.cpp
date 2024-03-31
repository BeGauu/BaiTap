#include <stdio.h>
#include <conio.h>

int nhapmang(int a[50], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\n nhap a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

int xuatmang(int a[50], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
}

int timkiem(int a[50], int n, int t) {
    int x,d = 0;
    for (int i = 0; i < n; i++)
    {while ((i < n) && (a[i] != t))
        d++;
    if (i == n) {
        printf("Khong tim thay!");
        return -1;
    } else {
        printf("\n %d o vi tri a[%d] ", t, i);
        printf("\n %d xuat hien %d lan!", x, d);
        return i;
    }
    }
}

int main() {
    int a[50], n, i, x;
    printf("\n Nhap so phan tu n = ");
    scanf("%d", &n);
    nhapmang(a, n);
    printf(" Mang vua nhap la: \n");
    xuatmang(a, n);
    printf("\n");
    printf("\n Nhap so can tim: ");
    scanf("%d", &x);
    timkiem(a, n, x);
    return 0;
}

