#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �?nh nghia c?u tr�c sinh vi�n
struct SinhVien {
    int maSV;
    char hoTen[50];
    int tuoi;
    struct SinhVien *next;
};

// H�m t?o m?t n�t m?i cho danh s�ch
struct SinhVien* taoNode(int maSV, char hoTen[], int tuoi) {
    struct SinhVien *sv = (struct SinhVien*)malloc(sizeof(struct SinhVien));
    sv->maSV = maSV;
    strcpy(sv->hoTen, hoTen);
    sv->tuoi = tuoi;
    sv->next = NULL;
    return sv;
}

// H�m ch�n m?t sinh vi�n v�o cu?i danh s�ch
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

// H�m duy?t v� hi?n th? danh s�ch sinh vi�n
void hienThiDanhSach(struct SinhVien *danhSach) {
    struct SinhVien *temp = danhSach;
    printf("Danh sach sinh vien:\n");
    while (temp != NULL) {
        printf("Ma SV: %d, Ho ten: %s, Tuoi: %d\n", temp->maSV, temp->hoTen, temp->tuoi);
        temp = temp->next;
    }
}

// H�m t�m ki?m sinh vi�n theo m� s? sinh vi�n
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

// H�m x�a sinh vi�n kh?i danh s�ch theo m� s? sinh vi�n
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
    
    // Th�m sinh vi�n v�o danh s�ch
    chenSinhVien(&danhSach, 1001, "Nguyen Van A", 20);
    chenSinhVien(&danhSach, 1002, "Tran Thi B", 21);
    chenSinhVien(&danhSach, 1003, "Le Van C", 22);

    // Hi?n th? danh s�ch
    hienThiDanhSach(danhSach);

    // T�m ki?m sinh vi�n
    int maSVTimKiem = 1002;
    struct SinhVien *svTimKiem = timKiemSinhVien(danhSach, maSVTimKiem);
    if (svTimKiem != NULL) {
        printf("Thong tin cua sinh vien co ma so %d:\n", maSVTimKiem);
        printf("Ho ten: %s, Tuoi: %d\n", svTimKiem->hoTen, svTimKiem->tuoi);
    } else {
        printf("Khong tim thay sinh vien co ma so %d\n", maSVTimKiem);
    }

    // X�a sinh vi�n
    int maSVXoa = 1002;
    xoaSinhVien(&danhSach, maSVXoa);
    hienThiDanhSach(danhSach);

    // Gi?i ph�ng b? nh?
    struct SinhVien *temp;
    while (danhSach != NULL) {
        temp = danhSach;
        danhSach = danhSach->next;
        free(temp);
    }

    return 0;
}

