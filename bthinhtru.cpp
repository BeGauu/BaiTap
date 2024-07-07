#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Ð?nh nghia c?u trúc d? li?u cho hình tr?
typedef struct {
    int stt;        // S? th? t?
    float duongkinh;    // Ðu?ng kính
    float bankinh;      // Bán kính
    float cao;          // Chi?u cao
    float thetich;      // Th? tích
} HinhTru;

// Khai báo ngan x?p
#define MAX_SIZE 100
HinhTru stack[MAX_SIZE];
int top = -1;

// Hàm push (d?y) ph?n t? vào ngan x?p
void push(HinhTru ht) {
    if (top == MAX_SIZE - 1) {
        printf("Ngan xep day, khong the them phan tu moi.\n");
    } else {
        top++;
        stack[top] = ht;
    }
}

// Hàm pop (l?y) ph?n t? t? ngan x?p
HinhTru pop() {
    HinhTru ht;
    if (top == -1) {
        printf("Ngan xep rong, khong the lay phan tu.\n");
    } else {
        ht = stack[top];
        top--;
    }
    return ht;
}

// Hàm tính th? tích c?a hình tr?
float tinhTheTich(float bankinh, float cao) {
    return M_PI * bankinh * bankinh * cao;
}

// Hàm main d? th?c thi chuong trình
int main() {
    int n;
    printf("Nhap so luong hinh tru: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        HinhTru ht;
        ht.stt = i + 1;
        printf("Nhap duong kinh cua hinh tru %d: ", i + 1);
        scanf("%f", &ht.duongkinh);
        ht.bankinh = ht.duongkinh / 2;
        printf("Nhap chieu cao cua hinh tru %d: ", i + 1);
        scanf("%f", &ht.cao);
        ht.thetich = tinhTheTich(ht.bankinh, ht.cao);
        
        push(ht); // Thêm hình tr? vào ngan x?p
    }
    
    printf("\nDanh sach cac hinh tru va thong tin ve the tich:\n");
    printf("Stt   Duong kinh   Ban kinh   Chieu cao   The tich\n");
    for (int i = 0; i < n; i++) {
        HinhTru ht = pop(); // L?y hình tr? ra t? ngan x?p
        printf("%-5d %-12.2f %-10.2f %-12.2f %-10.2f\n", ht.stt, ht.duongkinh, ht.bankinh, ht.cao, ht.thetich);
    }
    
    return 0;
}
