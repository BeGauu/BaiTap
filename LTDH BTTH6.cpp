#include <stdio.h>
#include <stack>
#include <stdlib.h>
#include <iostream>

int a[100][100], n, v;

// Hàm doc file
void docfile() {
    FILE *f = fopen("bt2.txt", "r");
    if (f == NULL) {
        printf("Khong co tap tin.\n");
        exit(0);
    } else {
        fscanf(f, "%d", &n); 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                fscanf(f, "%d", &a[i][j]); 
            }
        }
    }
    fclose(f);
}

// Hàm in ma tran ke
void infile() {
    printf("Ma tran ke:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

// Hàm kiem tra do thi có chu trình Euler không
bool tinhbac() {
    for (int i = 1; i <= n; i++) {
        int tong = 0;
        for (int j = 1; j <= n; j++) {
            tong += a[i][j]; // Tinh bac cua dinh i
        }
        if (tong % 2 != 0) {
            return false; // Neu có dinh có bac le, không có chu trình Euler
        }
    }
    return true; // Tat ca các dinh deu có bac chan
}

// Hàm tìm chu trình Euler
void euler(int v) {
    std::stack<int> S;
    int out[100], t = 0, ke;
    S.push(v); // Ðay dinh bat dau vào ngan xep

    while (!S.empty()) {
        int u = S.top(); // Lay dinh trên cùng cua ngan xep
        ke = 0;
        for (int i = 1; i <= n; i++) {
            if (a[u][i] > 0) { // Neu còn canh ke voi dinh u
                S.push(i);      // Ðay dinh ke vào ngan xep
                a[u][i]--;      // Giam so canh giua u và i
                a[i][u]--;      // Giam so canh giua i và u (vì do thi vô huong)
                ke = 1;         // Ðánh dau tìm thay canh ke
                break;
            }
        }
        if (ke == 0) { // Neu không còn canh ke
            S.pop();    // Xóa dinh trên cùng khoi ngan xep
            out[t++] = u; // Ðua dinh vào mang ket qua
        }
    }

    // In chu trình Euler
    printf("Chu trinh Euler: ");
    for (int i = t - 1; i >= 0; i--) {
        printf("%d ", out[i]);
    }
    printf("\n");
}

int main() {
    docfile(); 
    infile();  
    if (!tinhbac()) {
        printf("Do thi khong co chu trinh Euler.\n");
        return 0;
    }
    printf("Nhap dinh bat dau: ");
    scanf("%d", &v);
    euler(v); // Tìm chu trình Euler
    return 0;
}

