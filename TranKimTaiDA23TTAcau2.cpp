#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int stt;
    float duongkinh;
    float bankinh;
    float cao;
    float thetich;
} hinhtru;

typedef struct node {
    hinhtru data;
    struct node *link;
} node;

typedef struct stack {
    node *top;
} stack;

void khoitao(stack *s) {
    s->top = NULL;
}

int empty(stack *s) {
    return s->top == NULL ? 1 : 0;
}

void push(stack *s, hinhtru x) {
    node *p = (node *)malloc(sizeof(node));
    p->data = x;
    p->link = s->top;
    s->top = p;
}

hinhtru pop(stack *s) {
    if (empty(s)) {
        hinhtru ht;
        ht.stt = -1; // Giá tr? m?c d?nh khi stack r?ng
        return ht;
    }
    
    node *p = s->top;
    hinhtru ht = p->data;
    s->top = p->link;
    free(p);
    return ht;
}

float tinhTheTich(float bankinh, float cao) {
    return M_PI * bankinh * bankinh * cao;
}

float tinhBanKinh(float duongkinh) {
    return duongkinh / 2;
}

void ghiFile(char *tenFile, hinhtru *ht, int n) {
    FILE *f = fopen(tenFile, "w");
    if (f == NULL) {
        printf("Khong mo duoc file de ghi.\n");
        return;
    }

    fprintf(f, "Danh sach cac hinh tru va thong tin ve the tich:\n");
    fprintf(f, "Stt   Duong kinh   Ban kinh   Chieu cao   The tich\n");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%-5d %-12.2f %-10.2f %-12.2f %-10.2f\n", ht[i].stt, ht[i].duongkinh, ht[i].bankinh, ht[i].cao, ht[i].thetich);
    }

    fclose(f);
}

void docFile(char *tenFile, stack *s) {
    FILE *f = fopen(tenFile, "r");
    if (f == NULL) {
        printf("Khong mo duoc file de doc.\n");
        return;
    }

    hinhtru ht;
    khoitao(s);

    while (fscanf(f, "%d %f %f %f %f", &ht.stt, &ht.duongkinh, &ht.bankinh, &ht.cao, &ht.thetich) == 5) {
        push(s, ht);
    }

    fclose(f);
}

void hienthiDanhSach(stack *s) {
    if (empty(s)) {
        printf("Ngan xep rong, khong co du lieu.\n");
        return;
    }
    
    node *current = s->top;
    printf("\nDanh sach cac hinh tru va thong tin ve the tich:\n");
    printf("Stt   Duong kinh   Ban kinh   Chieu cao   The tich\n");
    while (current != NULL) {
        hinhtru ht = current->data;
        printf("%-5d %-12.2f %-10.2f %-12.2f %-10.2f\n", ht.stt, ht.duongkinh, ht.bankinh, ht.cao, ht.thetich);
        current = current->link;
    }
}



int main() {
    int choice, n;
    stack s;
    khoitao(&s);

    do {
        system("cls");
        printf("===== MENU =====\n");
        printf("1. Nhap thong tin hinh tru\n");
        printf("2. Hien thi thong tin hinh tru\n");
        printf("3. Ghi danh sach hinh tru vao file\n");
         printf("4. Doc danh sach hinh tru tu file\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so luong hinh tru: ");
                scanf("%d", &n);

                for (int i = 0; i < n; i++) {
                    hinhtru ht;
                    ht.stt = i + 1;
                    printf("\nNhap duong kinh cua hinh tru %d: ", i + 1);
                    scanf("%f", &ht.duongkinh);
                    ht.bankinh = tinhBanKinh(ht.duongkinh);
                    printf("Nhap chieu cao cua hinh tru %d: ", i + 1);
                    scanf("%f", &ht.cao);
                    ht.thetich = tinhTheTich(ht.bankinh, ht.cao);

                    push(&s, ht);
                }
                break;
            case 2:
                hienthiDanhSach(&s);
                break;
            case 3:
                if (empty(&s)) {
                    printf("Ngan xep rong, khong co du lieu de ghi.\n");
                } else {
                    int count = 0;
                    node *current = s.top;
                    hinhtru *dshinhtru = (hinhtru *)malloc(n * sizeof(hinhtru));
                    while (current != NULL) {
                        dshinhtru[count++] = pop(&s);
                        current = current->link;
                    }
                    ghiFile("danhsachhinhtru.txt", dshinhtru, n);
                    free(dshinhtru);
                }
                break;
                case 4:
                docFile("danhsachhinhtru.txt", &s);
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }

        printf("Nhan Enter de tiep tuc...");
        getchar();
        getchar(); // Dung de cho nguoi dung nhap Enter de tro ve menu

    } while (choice != 0);

    return 0;
}

