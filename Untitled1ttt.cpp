#include <stdio.h>
#include <stdlib.h>

// H?m kiem tra so nguy?n to
int isPrime(int num) {
    if (num <= 1) return 0; // Kh?ng ph?i s? nguy?n t?
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; // Kh?ng ph?i s? nguy?n t?
    }
    return 1; // L? s? nguy?n t?
}

// H?m s?p x?p m?ng theo gi?i thu?t tr?n RUN
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
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

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
// Hàm s?p x?p theo heapsort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    FILE *file_nguyen, *file_to, *file_sapxep, *file_kqtk;
    int num, n, arr[50];
    int so_nguyen[100], so_nguyen_to[100], so_sapxep[100];
    int count_nguyen = 0, count_nguyen_to = 0;

    // M? c?c file
    file_nguyen = fopen("songuyen.dat", "wb");
    file_to = fopen("songto.dat", "wb");
    file_sapxep = fopen("sapxep.dat", "wb");
    file_kqtk = fopen("kqtk.dat", "wb");

    // Nh?p c?c s? nguy?n v?o file songuyen.dat
    printf("Nhap cac so nguyen(Nhap 0 de ket thuc): ");
    while (1) {
        scanf("%d", &num);
        if (num == 0) break;
        fwrite(&num, sizeof(int), 1, file_nguyen);
        so_nguyen[count_nguyen++] = num;
    }
    rewind(file_nguyen); // ?ua con tr? file v? d?u file

    // T?m v? ghi c?c s? nguy?n t? v?o file songto.dat
    printf("Cac so nguyen to trong file songuyen.dat:\n");
    for (int i = 0; i < count_nguyen; i++) {
        fread(&num, sizeof(int), 1, file_nguyen);
        if (isPrime(num)) {
            fwrite(&num, sizeof(int), 1, file_to);
            so_nguyen_to[count_nguyen_to++] = num;
            printf("%d ", num);
        }
    }
    printf("\n");
    rewind(file_to);

    // S?p x?p m?ng c?c s? nguy?n theo gi?i thu?t tr?n RUN
    mergeSort(so_nguyen, 0, count_nguyen - 1);
    // Ghi m?ng d? s?p x?p v?o file sapxep.dat
    fwrite(so_nguyen, sizeof(int), count_nguyen, file_sapxep);
    printf("Noi dung file sapxep.dat:\n");
    for (int i = 0; i < count_nguyen; i++) {
        printf("%d ", so_nguyen[i]);
    }
    printf("\n");
// S?p x?p và luu vào file sapxep.dat
    file_nguyen = fopen("songuyen.dat", "rb");
    file_sapxep = fopen("sapxep.dat", "wb");
    printf("Sap xep cac so nguyen theo heapsort:\n");
    int i = 0;
    while (fread(&n, sizeof(int), 1, file_nguyen) == 1) {
        arr[i++] = n;
    }
    heapSort(arr, i);
    for (int j = 0; j < i; j++) {
        printf("%d ", arr[j]);
        fwrite(&arr[j], sizeof(int), 1, file_sapxep);
    }
    printf("\n");
    // Nh?p s? nguy?n c?n t?m ki?m
    printf("Nhap so nguyen can tim kiem: ");
    scanf("%d", &num);

    // Ki?m tra s? nguy?n c? trong file kh?ng v? ghi v?o file kqtk.dat
    for (int i = 0; i < count_nguyen; i++) {
        if (so_nguyen[i] == num) {
            fwrite(&num, sizeof(int), 1, file_kqtk);
            printf("So %d co trong file songuyen.dat\n", num);
            break;
        }
    }


    // ??ng c?c file
    fclose(file_nguyen);
    fclose(file_to);
    fclose(file_sapxep);
    fclose(file_kqtk);

    return 0;
}
