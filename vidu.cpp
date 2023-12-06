#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
int a[10][10],n,m;
void nhap();
void xuat();
void sapxep();


int main()
{ int key;
     while(true)
    {
         system("cls");
         printf("***********************************************************************\n");
         printf("**                       THAO TAC TREN CHUOI                         **\n");
         printf("**       1. Nhap/xuat mang 2 chieu                                   **\n");
         printf("**       2. Sap xep theo thu tu tang dan                             **\n");
         printf("**       3. Tinh tong cac phan tu la so nguyen to chia het cho 3     **\n");
         printf("**       0. Thoat                                                    **\n");
         printf("***********************************************************************\n");
         fflush(stdin);
         printf("\n \t\t     AN PHIM CHON: ");
         scanf("%d",&key);
         switch(key)
               {
                    case 1:
                    fflush(stdin);
                    nhap();
                    xuat();
                    printf("\nBam phim bat ky de tiep tuc!");
                    getch();
                    break;
                      
					  case 2:
					  printf("\n Sau khi sap xep ");
                      sapxep();
                      xuat();
                      printf("\nBam phim bat ky de tiep tuc!");
                      getch();
                      break;
                        
						case 0:
                        exit(1);
                        default:
                        printf("\nKhong co chuc nang nay!");
                        printf("\nBam phim bat ky de tiep tuc!");
                        getch();
                        break;
               }
    }
}

void nhap()
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

void xuat()
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

void sapxep()
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
