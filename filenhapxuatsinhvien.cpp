#include <stdio.h>

struct sinhvien {
  char ten[20];
  int tuoi;
  float diem;
};

void nhap(struct sinhvien *sv) {
  printf("Nhap ten sinh vien: ");
  scanf("%s", sv->ten);
  printf("Nhap tuoi sinh vien: ");
  scanf("%d", &sv->tuoi);
  printf("Nhap diem sinh vien: ");
  scanf("%f", &sv->diem);
}

void xuat(struct sinhvien *sv) {
  printf("Ten sinh vien: %s\n", sv->ten);
  printf("Tuoi sinh vien: %d\n", sv->tuoi);
  printf("Diem sinh vien: %.2f\n", sv->diem);
}

void nhapxuat(struct sinhvien *sv, int n, int index) {
  if (x < n) {
    nhap(&sv[x]);
    nhapxuat(sv, n, x + 1);
  } else {
    for (int i = 0; i < n; i++) {
      xuat(&sv[i]);
    }
  }
}

int main() {
  struct sinhvien sv[100];
  int n;

  printf("Nhap so luong sinh vien: ");
  scanf("%d", &n);

  nhapxuat(sv, n, 0);

  return 0;
}

