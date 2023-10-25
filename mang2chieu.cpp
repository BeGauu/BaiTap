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
void sapxep(int a[10][10], int m, int n){
	int k = m*n;
	for(int i=0; i<k-1; i++)
	{
		for(int j=i+1; j<k; j++)
		{ if(a[i/n][i%n]>a[j/n][j%n])
		       {
				int temp  = a[i/n][i%n];
				a[i/n][i%n] = a[j/n][j%n];
				a[j/n][j%n] = temp;
			   }  
		}
	}
	
}
int tongduongcheo(int a[10][10], int m,int n) {
  int tong = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
            if (i == j) {
        tong += a[i][j];
      }
    }
  } return tong;
}

int demsochan(int a[10][10], int m, int n) 
{  
  int dem = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      
      if (a[i][j] % 2 == 0) {
        dem++;
      }
    }
  }
 return dem;
}
bool kiemtra(int n)
{ int i;
 if (n<2)
 return false;
 for (i=2; i<=n/2;i++ )
    if (n%i==0) return false;
    return true;
}
int snt (int a[10][10], int m, int n)
{  int c=0, tong=0;
     for (int i=0; i<m; i++)
     { for (int j=0; j<n; j++)
         if (kiemtra(a[i][j])==true )
         tong= tong +a[i][j];
         c++;
     }printf ("\n So nguyen to trong ma tran : %d \n Tong so nguyen to :%d",c,tong);

}
void sole (int a[10][10], int m, int n) 
{
  for (int i = m - 1; i >= 0; i--) 
  {
    for (int j = n - 1; j >= 0; j--) 
	{
      if (a[i][j] % 2 == 1) 
	  {
      	printf ("\n Cac so le nam trong ma tran:%d  ", a[i][j]);
      }
    }
  }
}
int main()
{
	nhap(a, m, n);
	xuat(a, m, n);
	printf ("so chan nam trong tam giac tren cua duong cheo chinh %d \n",demsochan(a,m,n));
	printf("Tong cac phan tu tren duong cheo chinh : %d\n", tongduongcheo(a, m,n));
	snt(a,m,n);
	sole(a,m,n);
	printf("Gia tri lon nhat = %d", max(a, m, n));
	printf("\nGia tri nho nhat = %d", min(a, m, n));
	timkiem(a, m, n);
}

