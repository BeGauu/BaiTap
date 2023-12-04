#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int nhap(int a[10][10], int &m, int &n)
{
	
		printf("Nhap so dong m: ");
		scanf("%d", &m);
		printf("\nNhap so dong n: ");
		scanf("%d", &n);
	
	
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

void sapxep(int a[10][10], int m, int n)
{
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
/*bool kiemtra(int n)
{ 
   int i;
   if (n<2)
  return false;
 for (i=2; i<=n/2;i++ )
    if (n%i==0) 
	return false;
    return true;
}

int snt (int a[10][10], int m, int n)
{  int c=0, tong=0;
     for (int i=0; i<m; i++)
     { for (int j=0; j<n; j++)
         if (kiemtra(a[i][j]) %3 ==0 )
         {
         tong= tong +a[i][j];
         c++;
     }*/
int main()
{ int x,key;
    int a[10][10];
int m, n;

	while(true)
       { system("cls");
         printf("************************************************************************\n");
         printf("***     1.Nhap/xuat mang 2 chieu                                     ***\n");
         printf("***     2.Sap xep mang theo thu tu tang dan                          ***\n");
         printf("***     3.Tinh tong cac phan tu la so nguyen to chia het cho 3       ***\n");
         printf("***     0.Thoat                                                      ***\n");
         printf("************************************************************************\n");
	     fflush(stdin);
	     printf("\n          \t\t       AN PHIM CHON: ");
		 scanf ("%d",key);
		 switch(key)
		 { 
	      case 1:
	      	nhap(a,m,n);
	      	xuat(a,m,n);
	      	printf("\n Bam phim bat ky de tiep tuc!");
	      	getch ();
	      	break;
	      	
	      case 2:
	      	printf("\n Bam phim bat ky de tiep tuc!");
	      	sapxep(a,m,n);
	      	xuat(a,m,n);
	      	getch();
	      	break;
	      case 3:
	      	//int tong=snt(a,m,n);
	      	//printf("Tong cac snt chia het cho 3: %d\n",tong);
	      	break;
	      	case 0:
	         exit(1);
	         default:
	         	printf("\n Khong co chuc nang nay!");
	         	printf("\n Bam phim bat ky de tiep tuc!");
	         	getch();
	         	break;
	      	
		 }
	   }
}

