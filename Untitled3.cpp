

#include <stdio.h>

// Hàm nh?p m?ng
void nhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

// Hàm xu?t m?ng
void xuatMang(int a[], int n) {
    printf("Mang vua nhap la:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t ", a[i]);
    }
    printf("\n");
}

// Hàm t?m ki?m tuy?n tính
int timKiemTuyenTinh(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i; // Tr? v? v? trí c?a ph?n t? n?u t?m th?y
        }
    }
    return -1; // Tr? v? -1 n?u không t?m th?y
}


// Hàm ki?m tra s? nguyên t?
int kiemtra(int n) {
    if (n < 2) {
        return 0; // Không ph?i s? nguyên t?
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0; // Không ph?i s? nguyên t?
        }
    }
    return 1; // Là s? nguyên t?
}

// Hàm t?m s? l?n xu?t hi?n và v? trí c?a ph?n t? x
void vitri(int a[], int n, int x) {
    int dem = 0;
    printf("Vi tri cua %d: ", x);
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            printf("a[%d] ", i);
            dem++;
        }
    }
    printf("\n %d xuat hien %d lan\n", x,dem  );
}

// Hàm t?m và xu?t v? trí c?a s? nguyên t? trong m?ng
void snt(int a[], int n) {
    printf("Vi tri cac snt la:\n");
    for (int i = 0; i < n; i++) {
        if (kiemtra(a[i])) {
            printf("a[%d]\t", i);
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

    // T?m ki?m tuy?n tính
    int linearResult = timKiemTuyenTinh(a, n, x);
    if (linearResult != -1) {
        printf(" %d co trong mang\n Tai vi tri a[%d]\n", x, linearResult);
    } else {
        printf("%d khong co trong mang\n", x);
    }

    
    vitri(a, n, x);
    snt(a, n);

    return 0;
}
