
#include <stdio.h>

// H�m nh?p m?ng
void nhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

// H�m xu?t m?ng
void xuatMang(int a[], int n) {
    printf("Mang vua nhap la:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t ", a[i]);
    }
    printf("\n");
}

// H�m t?m ki?m tuy?n t�nh
int timKiemTuyenTinh(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i; // Tr? v? v? tr� c?a ph?n t? n?u t?m th?y
        }
    }
    return -1; // Tr? v? -1 n?u kh�ng t?m th?y
}

// H�m t?m ki?m nh? ph�n (m?ng c?n ��?c s?p x?p tr�?c)
int timKiemNhiPhan(int a[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return mid; // Tr? v? v? tr� c?a ph?n t? n?u t?m th?y
        }
        if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Tr? v? -1 n?u kh�ng t?m th?y
}

// H�m ki?m tra s? nguy�n t?
int kiemtra(int n) {
    if (n < 2) {
        return 0; // Kh�ng ph?i s? nguy�n t?
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0; // Kh�ng ph?i s? nguy�n t?
        }
    }
    return 1; // L� s? nguy�n t?
}

// H�m t?m s? l?n xu?t hi?n v� v? tr� c?a ph?n t? x
void vitri(int a[], int n, int x) {
    int dem = 0;
    printf("Vi tri cua phan tu %d la:\n", x);
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            printf("%d ", i);
            dem++;
        }
    }
    printf("\n %d xuat hien %d lan\n", x,dem  );
}

// H�m t?m v� xu?t v? tr� c?a s? nguy�n t? trong m?ng
void snt(int a[], int n) {
    printf("Vi tri cac snt la:\n");
    for (int i = 0; i < n; i++) {
        if (kiemtra(a[i])) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Nhap so phan tu mang: ");
    scanf("%d", &n);
    int a[50];

    nhapMang(a, n);
    xuatMang(a, n);

    int x;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);

    // T?m ki?m tuy?n t�nh
    int linearResult = timKiemTuyenTinh(a, n, x);
    if (linearResult != -1) {
        printf("Phan tu %d co trong mang\n Tai vi tri a[%d]\n", x, linearResult);
    } else {
        printf("Phan tu %d khong co trong mang\n", x);
    }

    
    vitri(a, n, x);
    snt(a, n);

    return 0;
}
