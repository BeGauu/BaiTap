#include <stdio.h>
#include <stdlib.h>
#define vocung 1000

int a[100][100], n, L[100], s, d[100], truoc[100];

void docfile() {
    FILE *f = fopen("bt2.txt", "r");
    if (f == NULL) {
        printf("Không có t?p tin\n");
        exit(1);
    }
    fscanf(f, "%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fscanf(f, "%d", &a[i][j]);
        }
    }
    fclose(f);
}

void infile() {
    printf("Ma tr?n k?:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void khoitao(int s) {
    for (int i = 1; i <= n; i++) {
        L[i] = vocung;
        d[i] = 0;
        truoc[i] = 0;
    }
    L[s] = 0;
}

int vitrimin() {
    int min = vocung;
    int vt = -1;
    for (int i = 1; i <= n; i++) {
        if (L[i] < min && d[i] == 0) {
            min = L[i];
            vt = i;
        }
    }
    return vt;
}

void capnhatke_p(int p) {
    for (int i = 1; i <= n; i++) {
        if (a[p][i] != 0 && d[i] == 0) {
            if (L[i] > L[p] + a[p][i]) {
                L[i] = L[p] + a[p][i];
                truoc[i] = p;
            }
        }
    }
}

void timduong(int f) {
    printf("Ð? dài du?ng di t? %d d?n %d là: %d\n", s, f, L[f]);
    printf("Ðu?ng di: ");
    int y = f;
    while (y != 0) {
        printf("%d ", y);
        y = truoc[y];
    }
    printf("\n");
}

void Dijkstra() {
    printf("Nh?p d?nh xu?t phát: ");
    scanf("%d", &s);

    khoitao(s);

    for (int lap = 1; lap <= n; lap++) {
        int u = vitrimin();
        if (u == -1) break;
        capnhatke_p(u);
        d[u] = 1;
    }

    int f;
    printf("Nh?p d?nh k?t thúc: ");
    scanf("%d", &f);

    timduong(f);
}

int main() {
    docfile();
    infile();
    Dijkstra();
    return 0;
}

