#include <stdio.h>
#include <stdlib.h>
void nhapghimang(int *a, int n, char *filename);
void xulymang(int *a, int n);

int main()
{
  int n;
  printf("Nhap so phan tu cua mang: ");
  scanf("%d", &n);

  int *a = (int *)malloc(n * sizeof(int)); 

  nhapghimang(a, n, "mang.txt");
  xulymang(a, n);
  free(a); 
  return 0;
}

void nhapghimang(int *a, int n, char *filename)
{
  FILE *fp;
  fp = fopen(filename, "w");
  if (fp == NULL)
  {
    printf("Khong the mo file\n");
    return;
  }
  for (int i = 0; i < n; i++)
  {
    printf("Nhap phan tu thu %d: ", i);
    scanf("%d", &a[i]);
    fprintf(fp, "%d\n", a[i]);
  }
  fclose(fp);
}

void xulymang(int *a, int n)
{
  int sum = 0, max = a[0], min = a[0];
  for (int i = 0; i < n; i++)
  {
    sum += a[i];
    if (a[i] > max)
    {
      max = a[i];
    }
    if (a[i] < min)
    {
      min = a[i];
    }
  }
  printf("Tong cac phan tu trong mang: %d\n", sum);
  printf("Phan tu lon nhat trong mang: %d\n", max);
  printf("Phan tu nho nhat trong mang: %d\n", min);
}

