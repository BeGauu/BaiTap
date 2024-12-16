#include <stdio.h>
#include <stdlib.h>
#define vocung 1000

int a[100][100], n, L[100], s, d[100], truoc[100], tam [100];

void docfile() {
    FILE *f = fopen("bt2.txt", "r");
    if (f == NULL) {
        printf("Khong co tap tin\n");
        exit(1); // Thoát chuong trình n?u không tìm th?y file
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
    printf("Ma tran ke:\n");
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
    int vt = 0;
    for (int i = 1; i <= n; i++) {
        if (L[i] < min && d[i] == 0) { 
            min = L[i];
            vt = i;
        }
    }
    return vt;
}

void capnhat(int vt) {
    for (int i = 1; i <= n; i++) 
        if (a[vt][i] != 0 && d[i] == 0) 
            if (L[i] > L[vt] + a[vt][i]) { 
                L[i] = L[vt] + a[vt][i];   
                truoc[i] = vt;            
            }
        
    
}

void timduong(int f) {
    printf("\nDo dai DDNN tu dinh %d den dinh %d la: %d\n", s, f, L[f]);
    printf("Duong di: ");
    tam[0]=f;
    int i=1;
    
    while (truoc[f] != 0) {
    	tam[i]=truoc[f];
        i++;
        f = truoc[f];           
    }
    for (int j=i-1; j>=0;j--)
    printf ("%d",tam[j]);
}

int main() {
    int f;
    docfile(); 
    infile();  
    printf("Nhap dinh bat dau: ");
    scanf("%d", &s);
    khoitao(s);

    int lap = 1;
    while (lap < n) {
        int vt = vitrimin(); 
        if (vt == 0) break;  
        capnhat(vt);         
        d[vt] = 1;           
        lap++;
    }

    printf("Nhap dinh ket thuc: ");
    scanf("%d", &f);

    for (int i = 1; i <= n; i++) {
        printf("%d ", L[i]);
    }
    printf ("\n");

    for (int i = 1; i <= n; i++) {
        printf("%d ", truoc[i]);
    }

    timduong(f);
    return 0;
}

