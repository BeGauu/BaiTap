#include "stdio.h"
int a[10][10];
int m, n;

void nhap(int a[10][10], int &m, int &n)
{
	{
		printf("Nhap so dong m: ");
		scanf("%d", &m);
		printf("\nNhap so dong n: ");
		scanf("%d", &n);
	}
	
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("a[%d][%d]=", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void xuat(int a[10][10], int m, int n)
{
	printf("\nMa tran vua nhap: \n");
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

int max(int [10][10], int m, int n)
{
	int max = a[0][0];
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(max<a[i][j]){
				max = a[i][j];
			}
		}
	}
	return max;
}

int min(int a[10][10], int m, int n)
{
	int min = a[0][0];
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{ if(min>a[i][j])
		   {
				min = a[i][j];
		   }   
	    }
	}
	return min;
}
/*bool isPrime(int a[][10], int m, int n) {

  if (a[i][j] <= 1) {
    return false;
  }
   for (int i = 2; i * i <= a[i][j]; i++) {
        if (a[i][j] % i == 0) {
      return false;
    }
  }
  return true;
}
int songuyento(int a[10][10], int m, int n)
{for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (isPrime(a[i][j])) {
        printf("%d ", a[i][j]);
      }
    }
  }
}*/
int timkiem(int a[10][10], int m, int n){
	int x;
	int count=0;
  printf("\n Nhap gia tri x can tim: ");
  scanf("%d", &x);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == x) {
        printf("x o vi tri  (%d, %d)\n", i, j);
        count++;
      }
    }
  }
 if (count==0){printf ("Khong tim thay x");
 }
}
int main()
{
	nhap(a, m, n);
	xuat(a, m, n);
	printf("Gia tri lon nhat = %d", max(a, m, n));
	printf("\nGia tri nho nhat = %d", min(a, m, n));
	//songuyento(a,m,n);
	timkiem(a, m, n);
}

