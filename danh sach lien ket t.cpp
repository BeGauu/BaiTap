#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �?nh nghia c?u tr�c SinhVien
struct SinhVien {
    int maSV;
    char hoTen[50];
    int tuoi;
    struct SinhVien *next;
};

// H�m t?o m?t n�t m?i v?i th�ng tin v? sinh vi�n
struct SinhVien *taoSinhVien(int maSV, char *hoTen, int tuoi) {
    struct SinhVien *sv = (struct SinhVien *)malloc(sizeof(struct SinhVien));
    if (sv == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    sv->maSV = maSV;
    strcpy(sv->hoTen, hoTen);
    sv->tuoi = tuoi;
    sv->next = NULL;
    return sv;
}

// H�m ch�n m?t sinh vi�n v�o d?u danh s�ch
void chenDau(struct SinhVien **dauDS, struct SinhVien *sv) {
    sv->next = *dauDS;
    *dauDS = sv;
}

// H�m duy?t v� in ra th�ng tin c?a t?t c? sinh vi�n trong danh s�ch
void duyetDanhSach(struct SinhVien *dauDS) {
    struct SinhVien *temp = dauDS;
    while (temp != NULL) {
        printf("Ma SV: %d\tHo ten: %s\tTuoi: %d\n", temp->maSV, temp->hoTen, temp->tuoi);
        temp = temp->next;
    }
}

// H�m t�m ki?m sinh vi�n theo m� SV
struct SinhVien *timSinhVien(struct SinhVien *dauDS, int maSV) {
    struct SinhVien *temp = dauDS;
    while (temp != NULL) {
        if (temp->maSV == maSV)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// H�m x�a sinh vi�n kh?i danh s�ch theo m� SV
void xoaSinhVien(struct SinhVien **dauDS, int maSV) {
    struct SinhVien *temp = *dauDS;
    struct SinhVien *prev = NULL;
    if (temp != NULL && temp->maSV == maSV) {
        *dauDS = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->maSV != maSV) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

// H�m main
int main() {
    struct SinhVien *dauDS = NULL; // Kh?i t?o danh s�ch sinh vi�n r?ng

    // Th�m sinh vi�n v�o danh s�ch
    chenDau(&dauDS, taoSinhVien(1, "Nguyen Van A", 20));
    chenDau(&dauDS, taoSinhVien(2, "Tran Thi B", 21));
    chenDau(&dauDS, taoSinhVien(3, "Le Van C", 22));

    // In ra th�ng tin c?a t?t c? sinh vi�n
    printf("Danh sach sinh vien:\n");
    duyetDanhSach(dauDS);

    // T�m ki?m v� in ra th�ng tin c?a m?t sinh vi�n
    int maSV_timkiem = 2;
    struct SinhVien *sv_timkiem = timSinhVien(dauDS, maSV_timkiem);
    if (sv_timkiem != NULL) {
        printf("\nThong tin sinh vien co ma SV %d:\n", maSV_timkiem);
        printf("Ma SV: %d\tHo ten: %s\tTuoi: %d\n", sv_timkiem->maSV, sv_timkiem->hoTen, sv_timkiem->tuoi);
    } else {
        printf("\nKhong tim thay sinh vien co ma SV %d\n", maSV_timkiem);
    }

    // X�a m?t sinh vi�n kh?i danh s�ch
    int maSV_xoa = 1;
    xoaSinhVien(&dauDS, maSV_xoa);
    printf("\nDanh sach sinh vien sau khi xoa sinh vien co ma SV %d:\n", maSV_xoa);
    duyetDanhSach(dauDS);

    return 0;
}

