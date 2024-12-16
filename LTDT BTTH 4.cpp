#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int a[10][10], n, d[10], x;

void docfile() {
    FILE *f;
    f = fopen("bt2.txt", "r");
    if (f == NULL) {
        printf("Khong co tap tin\n");
        exit(1);
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

void infile() {
    printf("Ma tran ke:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void bfs(int x) {
    queue<int> q;
    q.push(x); 

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (d[u] == 0) {
            printf("%d ", u); 
            d[u] = -1;        
        }

        for (int y = 1; y <= n; y++) {
            if (a[u][y] != 0 && d[y] == 0) {
                q.push(y);
            }
        }
    }
}

int main() {
    docfile(); 
    infile();  

    for (int i = 1; i <= n; i++) {
        d[i] = 0;
    }
    printf("Dinh can duyet: ");
    scanf("%d", &x);
    bfs(x);

    return 0;
}
