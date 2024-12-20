#include <stdio.h>
#include <stack>
#include <stdlib.h>
#include <iostream>

int a[100][100], n, v;

// H�m doc file
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

// H�m in ma tran ke
void infile() {
    printf("Ma tran ke:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

// H�m kiem tra do thi c� chu tr�nh Euler kh�ng
bool tinhbac() {
    for (int i = 1; i <= n; i++) {
        int tong = 0;
        for (int j = 1; j <= n; j++) {
            tong += a[i][j]; // Tinh bac cua dinh i
        }
        if (tong % 2 != 0) {
            return false; // Neu c� dinh c� bac le, kh�ng c� chu tr�nh Euler
        }
    }
    return true; // Tat ca c�c dinh deu c� bac chan
}

// H�m t�m chu tr�nh Euler
void euler(int v) {
    std::stack<int> S;
    int out[100], t = 0, ke;
    S.push(v); // �ay dinh bat dau v�o ngan xep

    while (!S.empty()) {
        int u = S.top(); // Lay dinh tr�n c�ng cua ngan xep
        ke = 0;
        for (int i = 1; i <= n; i++) {
            if (a[u][i] > 0) { // Neu c�n canh ke voi dinh u
                S.push(i);      // �ay dinh ke v�o ngan xep
                a[u][i]--;      // Giam so canh giua u v� i
                a[i][u]--;      // Giam so canh giua i v� u (v� do thi v� huong)
                ke = 1;         // ��nh dau t�m thay canh ke
                break;
            }
        }
        if (ke == 0) { // Neu kh�ng c�n canh ke
            S.pop();    // X�a dinh tr�n c�ng khoi ngan xep
            out[t++] = u; // �ua dinh v�o mang ket qua
        }
    }

    // In chu tr�nh Euler
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
    euler(v); // T�m chu tr�nh Euler
    return 0;
}

