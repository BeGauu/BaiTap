#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Ki?m tra s? nguy�n t?
int isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}

// H�m tr?n hai m?ng d� du?c s?p x?p
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // T?o c�c m?ng t?m th?i
    int L[n1], R[n2];

    // Sao ch�p d? li?u v�o c�c m?ng t?m th?i L[] v� R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Tr?n c�c m?ng t?m th?i v�o arr[l..r]
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

    // Sao ch�p c�c ph?n t? c�n l?i c?a L[] n?u c�
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao ch�p c�c ph?n t? c�n l?i c?a R[] n?u c�
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

// Ghi m?ng v�o file
void writeToFile(int arr[], int n, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Kh�ng th? m? file %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", arr[i]);
    }
    fclose(file);
}

// �?c m?ng t? file
int* readFromFile(char *filename, int *n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Kh�ng th? m? file %s\n", filename);
        exit(1);
    }
    // �?m s? lu?ng s? trong file
    *n = 0;
    int num;
    while (fscanf(file, "%d", &num) == 1) {
        (*n)++;
    }
    // �?c d? li?u v�o m?ng
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

    // Nh?p m?ng v� ghi v�o file songuyen.dat
    printf("Nh?p s? lu?ng s? nguy�n: ");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    printf("Nh?p c�c s? nguy�n:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    writeToFile(arr, n, "songuyen.dat");

    // T�m v� ghi c�c s? nguy�n t? v�o file songto.dat
    FILE *fileTo = fopen("songto.dat", "w");
    if (fileTo == NULL) {
        printf("Kh�ng th? t?o file songto.dat\n");
        exit(1);
    }
    printf("C�c s? nguy�n t? trong file songuyen.dat:\n");
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            fprintf(fileTo, "%d\n", arr[i]);
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    fclose(fileTo);

    // S?p x?p m?ng v� ghi v�o file sapxep.dat
    mergeSort(arr, 0, n - 1);
    writeToFile(arr, n, "sapxep.dat");

    // Hi?n th? n?i dung file sapxep.dat
    printf("N?i dung file sapxep.dat:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // T�m ki?m s? nguy�n trong file songuyen.dat
    int searchNum;
    printf("Nh?p s? nguy�n c?n t�m ki?m: ");
    scanf("%d", &searchNum);
    FILE *fileKQTK = fopen("kqtk.dat", "w");
    if (fileKQTK == NULL) {
        printf("Kh�ng th? t?o file kqtk.dat\n");
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
        printf("S? nguy�n %d t?n t?i trong file songuyen.dat\n", searchNum);
    } else {
        printf("S? nguy�n %d kh�ng t?n t?i trong file songuyen.dat\n", searchNum);
    }
    fclose(fileKQTK);

    free(arr);
    return 0;
}
