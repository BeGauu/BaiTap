#include <stdio.h>
void nhapmang(int a[], int n)
{
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}
void tinhtoan(int a[], int n, char* tep)
{
    int sum = 0;
    int max = a[0];
    int min = a[0];

    for (int i = 0; i < n; i++) {
        sum += a[i];

        if (a[i] > max) {
            max = a[i];
        }

        if (a[i] < min) {
            min = a[i];
        }
    }

    FILE* f = fopen(tep, "a");
    if (f == NULL) {
        printf("Loi mo tep!\n");
        return;
    }

    fprintf(f, "\nTong cac phan tu: %d\n", sum);
    fprintf(f, "Phan tu lon nhat: %d\n", max);
    fprintf(f, "Phan tu nho nhat: %d\n", min);

    fclose(f);
}
void ghimang(int a[], int n, char* tep)
{
    FILE* f = fopen(tep, "w");
    if (f == NULL) {
        printf("Loi mo tep!\n");
        return;
    }

    fprintf(f, "Mang co %d phan tu: ", n);
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d ", a[i]);
    }

    fclose(f);
}


void docfile(char* tep)
{
    FILE* f = fopen(tep, "r");
    if (f == NULL) {
        printf("Loi mo tep!\n");
        return;
    }

    printf("\nNoi dung file: %s\n", tep);
    char ch;
    while ((ch = fgetc(f)) != EOF) {
        putchar(ch);
    }

    fclose(f);
}
int main()
{
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    int a[n];

    nhapmang(a, n);

    char tep[100];
    printf("Nhap duong dan file: ");
    scanf("%s", tep);
    ghimang(a, n, tep);
    tinhtoan(a, n, tep);
    docfile(tep);
    return 0;
}

