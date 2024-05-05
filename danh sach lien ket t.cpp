#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ð?nh nghia c?u trúc SinhVien
struct SinhVien {
    int maSV;
    char hoTen[50];
    int tuoi;
    struct SinhVien *next;
};

// Hàm t?o m?t nút m?i v?i thông tin v? sinh viên
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

// Hàm chèn m?t sinh viên vào d?u danh sách
void chenDau(struct SinhVien **dauDS, struct SinhVien *sv) {
    sv->next = *dauDS;
    *dauDS = sv;
}

// Hàm duy?t và in ra thông tin c?a t?t c? sinh viên trong danh sách
void duyetDanhSach(struct SinhVien *dauDS) {
    struct SinhVien *temp = dauDS;
    while (temp != NULL) {
        printf("Ma SV: %d\tHo ten: %s\tTuoi: %d\n", temp->maSV, temp->hoTen, temp->tuoi);
        temp = temp->next;
    }
}

// Hàm tìm ki?m sinh viên theo mã SV
struct SinhVien *timSinhVien(struct SinhVien *dauDS, int maSV) {
    struct SinhVien *temp = dauDS;
    while (temp != NULL) {
        if (temp->maSV == maSV)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// Hàm xóa sinh viên kh?i danh sách theo mã SV
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

// Hàm main
int main() {
    struct SinhVien *dauDS = NULL; // Kh?i t?o danh sách sinh viên r?ng

    // Thêm sinh viên vào danh sách
    chenDau(&dauDS, taoSinhVien(1, "Nguyen Van A", 20));
    chenDau(&dauDS, taoSinhVien(2, "Tran Thi B", 21));
    chenDau(&dauDS, taoSinhVien(3, "Le Van C", 22));

    // In ra thông tin c?a t?t c? sinh viên
    printf("Danh sach sinh vien:\n");
    duyetDanhSach(dauDS);

    // Tìm ki?m và in ra thông tin c?a m?t sinh viên
    int maSV_timkiem = 2;
    struct SinhVien *sv_timkiem = timSinhVien(dauDS, maSV_timkiem);
    if (sv_timkiem != NULL) {
        printf("\nThong tin sinh vien co ma SV %d:\n", maSV_timkiem);
        printf("Ma SV: %d\tHo ten: %s\tTuoi: %d\n", sv_timkiem->maSV, sv_timkiem->hoTen, sv_timkiem->tuoi);
    } else {
        printf("\nKhong tim thay sinh vien co ma SV %d\n", maSV_timkiem);
    }

    // Xóa m?t sinh viên kh?i danh sách
    int maSV_xoa = 1;
    xoaSinhVien(&dauDS, maSV_xoa);
    printf("\nDanh sach sinh vien sau khi xoa sinh vien co ma SV %d:\n", maSV_xoa);
    duyetDanhSach(dauDS);

    return 0;
}

