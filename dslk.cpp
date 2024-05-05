#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ð?nh nghia c?u trúc sinh viên
struct SinhVien {
    int maSV;
    char hoTen[50];
    int tuoi;
    struct SinhVien *next;
};

// Hàm t?o m?t nút m?i cho danh sách
struct SinhVien* taoNode(int maSV, char hoTen[], int tuoi) {
    struct SinhVien *sv = (struct SinhVien*)malloc(sizeof(struct SinhVien));
    sv->maSV = maSV;
    strcpy(sv->hoTen, hoTen);
    sv->tuoi = tuoi;
    sv->next = NULL;
    return sv;
}

// Hàm chèn m?t sinh viên vào cu?i danh sách
void chenSinhVien(struct SinhVien **danhSach, int maSV, char hoTen[], int tuoi) {
    struct SinhVien *svMoi = taoNode(maSV, hoTen, tuoi);
    if (*danhSach == NULL) {
        *danhSach = svMoi;
    } else {
        struct SinhVien *temp = *danhSach;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = svMoi;
    }
}

// Hàm duy?t và hi?n th? danh sách sinh viên
void hienThiDanhSach(struct SinhVien *danhSach) {
    struct SinhVien *temp = danhSach;
    printf("Danh sach sinh vien:\n");
    while (temp != NULL) {
        printf("Ma SV: %d, Ho ten: %s, Tuoi: %d\n", temp->maSV, temp->hoTen, temp->tuoi);
        temp = temp->next;
    }
}

// Hàm tìm ki?m sinh viên theo mã s? sinh viên
struct SinhVien* timKiemSinhVien(struct SinhVien *danhSach, int maSV) {
    struct SinhVien *temp = danhSach;
    while (temp != NULL) {
        if (temp->maSV == maSV) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Hàm xóa sinh viên kh?i danh sách theo mã s? sinh viên
void xoaSinhVien(struct SinhVien **danhSach, int maSV) {
    struct SinhVien *temp = *danhSach;
    struct SinhVien *prev = NULL;
    while (temp != NULL && temp->maSV != maSV) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Khong tim thay sinh vien co ma so %d\n", maSV);
        return;
    }
    if (prev == NULL) {
        *danhSach = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Da xoa sinh vien co ma so %d\n", maSV);
}

int main() {
    struct SinhVien *danhSach = NULL;
    
    // Thêm sinh viên vào danh sách
    chenSinhVien(&danhSach, 1001, "Nguyen Van A", 20);
    chenSinhVien(&danhSach, 1002, "Tran Thi B", 21);
    chenSinhVien(&danhSach, 1003, "Le Van C", 22);

    // Hi?n th? danh sách
    hienThiDanhSach(danhSach);

    // Tìm ki?m sinh viên
    int maSVTimKiem = 1002;
    struct SinhVien *svTimKiem = timKiemSinhVien(danhSach, maSVTimKiem);
    if (svTimKiem != NULL) {
        printf("Thong tin cua sinh vien co ma so %d:\n", maSVTimKiem);
        printf("Ho ten: %s, Tuoi: %d\n", svTimKiem->hoTen, svTimKiem->tuoi);
    } else {
        printf("Khong tim thay sinh vien co ma so %d\n", maSVTimKiem);
    }

    // Xóa sinh viên
    int maSVXoa = 1002;
    xoaSinhVien(&danhSach, maSVXoa);
    hienThiDanhSach(danhSach);

    // Gi?i phóng b? nh?
    struct SinhVien *temp;
    while (danhSach != NULL) {
        temp = danhSach;
        danhSach = danhSach->next;
        free(temp);
    }

    return 0;
}

