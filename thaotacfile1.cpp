#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Ki?m tra s? nguyên t?
int isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}

// Hàm tr?n hai m?ng dã du?c s?p x?p
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // T?o các m?ng t?m th?i
    int L[n1], R[n2];

    // Sao chép d? li?u vào các m?ng t?m th?i L[] và R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Tr?n các m?ng t?m th?i vào arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các ph?n t? còn l?i c?a L[] n?u có
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các ph?n t? còn l?i c?a R[] n?u có
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Gi?i thu?t tr?n RUN
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Ghi m?ng vào file
void writeToFile(int arr[], int n, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Không th? m? file %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", arr[i]);
    }
    fclose(file);
}

// Ð?c m?ng t? file
int* readFromFile(char *filename, int *n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Không th? m? file %s\n", filename);
        exit(1);
    }
    // Ð?m s? lu?ng s? trong file
    *n = 0;
    int num;
    while (fscanf(file, "%d", &num) == 1) {
        (*n)++;
    }
    // Ð?c d? li?u vào m?ng
    int *arr = (int*)malloc((*n) * sizeof(int));
    rewind(file);
    int i = 0;
    while (fscanf(file, "%d", &num) == 1) {
        arr[i++] = num;
    }
    fclose(file);
    return arr;
}

int main() {
    int n;
    int *arr;

    // Nh?p m?ng và ghi vào file songuyen.dat
    printf("Nh?p s? lu?ng s? nguyên: ");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    printf("Nh?p các s? nguyên:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    writeToFile(arr, n, "songuyen.dat");

    // Tìm và ghi các s? nguyên t? vào file songto.dat
    FILE *fileTo = fopen("songto.dat", "w");
    if (fileTo == NULL) {
        printf("Không th? t?o file songto.dat\n");
        exit(1);
    }
    printf("Các s? nguyên t? trong file songuyen.dat:\n");
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            fprintf(fileTo, "%d\n", arr[i]);
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    fclose(fileTo);

    // S?p x?p m?ng và ghi vào file sapxep.dat
    mergeSort(arr, 0, n - 1);
    writeToFile(arr, n, "sapxep.dat");

    // Hi?n th? n?i dung file sapxep.dat
    printf("N?i dung file sapxep.dat:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Tìm ki?m s? nguyên trong file songuyen.dat
    int searchNum;
    printf("Nh?p s? nguyên c?n tìm ki?m: ");
    scanf("%d", &searchNum);
    FILE *fileKQTK = fopen("kqtk.dat", "w");
    if (fileKQTK == NULL) {
        printf("Không th? t?o file kqtk.dat\n");
        exit(1);
    }
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == searchNum) {
            found = 1;
            break;
        }
    }
    if (found) {
        fprintf(fileKQTK, "%d\n", searchNum);
        printf("S? nguyên %d t?n t?i trong file songuyen.dat\n", searchNum);
    } else {
        printf("S? nguyên %d không t?n t?i trong file songuyen.dat\n", searchNum);
    }
    fclose(fileKQTK);

    free(arr);
    return 0;
}
