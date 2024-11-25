#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // S? d?nh t?i da c?a d? th?

int a[10][10], n;  // Ma tr?n k? và s? d?nh
int visited[MAX];  // M?ng dánh d?u các d?nh dã du?c duy?t
int stack[MAX];    // Ngan x?p
int top = -1;      // Ch? s? ph?n t? trên cùng c?a ngan x?p

// Hàm d?c ma tr?n k? t? file
void docfile() {
    FILE *f;
    f = fopen("bt2.txt", "r");
    if (f == NULL) {
        printf("Không có t?p tin\n");
        exit(1); // Thoát chuong trình n?u không tìm th?y file
    }
    fscanf(f, "%d", &n); // Ð?c s? d?nh
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fscanf(f, "%d", &a[i][j]); // Ð?c ma tr?n k?
        }
    }
    fclose(f); // Ðóng file
}

// Hàm in ma tr?n k? ra màn hình
void infile() {
    printf("Ma tran ke:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Hàm thêm m?t ph?n t? vào ngan x?p
void push(int value) {
    stack[++top] = value;
}

// Hàm l?y ph?n t? trên cùng kh?i ngan x?p
int pop() {
    return stack[top--];
}

// Hàm ki?m tra ngan x?p r?ng
int isempty() {
    return top == -1;
}

// Hàm DFS s? d?ng ngan x?p
void DFS(int start) {
    push(start); // Thêm d?nh b?t d?u vào ngan x?p

    // L?p cho d?n khi ngan x?p r?ng
    while (!isempty()) {
        int current = pop(); // L?y ph?n t? trên cùng c?a ngan x?p

        // N?u d?nh này chua du?c duy?t
        if (!visited[current]) {
            printf("%d ", current); // In d?nh này
            visited[current] = 1;   // Ðánh d?u dã duy?t

            // Duy?t t?t c? các d?nh k? v?i d?nh hi?n t?i
            for (int i = 1; i <= n; i++) {
                if (a[current][i] == 1 && !visited[i]) {
                    push(i); // Thêm các d?nh k? chua duy?t vào ngan x?p
                }
            }
        }
    }
}

int main() {
    int start; // Ð?nh b?t d?u

    // Ð?c d? li?u t? file và in ra ma tr?n k?
    docfile();
    infile();

    // Nh?p d?nh b?t d?u
    printf("Nhap dinh bat dau: ");
    scanf("%d", &start);

    // Th?c hi?n DFS
    printf("Thu tu duyet DFS: ");
    DFS(start);

    return 0;
}
