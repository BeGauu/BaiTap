#include <stdio.h>
#include <stdlib.h>

// Hàm kiem tra so nguyên to
int isPrime(int num) {
    if (num <= 1) return 0; // Không ph?i s? nguyên t?
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; // Không ph?i s? nguyên t?
    }
    return 1; // Là s? nguyên t?
}

// Hàm s?p x?p m?ng theo gi?i thu?t tr?n RUN
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

int main() {
    FILE *file_nguyen, *file_to, *file_sapxep, *file_kqtk;
    int num;
    int so_nguyen[100], so_nguyen_to[100], so_sapxep[100];
    int count_nguyen = 0, count_nguyen_to = 0;

    // M? các file
    file_nguyen = fopen("songuyen.dat", "wb");
    file_to = fopen("songto.dat", "wb");
    file_sapxep = fopen("sapxep.dat", "wb");
    file_kqtk = fopen("kqtk.dat", "wb");

    // Nh?p các s? nguyên vào file songuyen.dat
    printf("Nhap cac so nguyen(Nhap 0 de ket thuc): ");
    while (1) {
        scanf("%d", &num);
        if (num == 0) break;
        fwrite(&num, sizeof(int), 1, file_nguyen);
        so_nguyen[count_nguyen++] = num;
    }
    rewind(file_nguyen); // Ðua con tr? file v? d?u file

    // Tìm và ghi các s? nguyên t? vào file songto.dat
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

    // S?p x?p m?ng các s? nguyên theo gi?i thu?t tr?n RUN
    mergeSort(so_nguyen, 0, count_nguyen - 1);
    // Ghi m?ng dã s?p x?p vào file sapxep.dat
    fwrite(so_nguyen, sizeof(int), count_nguyen, file_sapxep);
    printf("Noi dung file sapxep.dat:\n");
    for (int i = 0; i < count_nguyen; i++) {
        printf("%d ", so_nguyen[i]);
    }
    printf("\n");

    // Nh?p s? nguyên c?n tìm ki?m
    printf("Nhap so nguyen can tim kiem: ");
    scanf("%d", &num);

    // Ki?m tra s? nguyên có trong file không và ghi vào file kqtk.dat
    for (int i = 0; i < count_nguyen; i++) {
        if (so_nguyen[i] == num) {
            fwrite(&num, sizeof(int), 1, file_kqtk);
            printf("So %d co trong file songuyen.dat\n", num);
            break;
        }
    }

    // Ðóng các file
    fclose(file_nguyen);
    fclose(file_to);
    fclose(file_sapxep);
    fclose(file_kqtk);

    return 0;
}
