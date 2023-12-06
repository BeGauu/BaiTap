#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct
{
	char mssv[10];
	char hoten[50];
}sinhvien;

void doctep(char*tep);
void viettep(char*tep);
void timkiemtep(char*tep);

int main()
{
	int c;
	for(;;)
	{
		printf("*********************************\n");
        printf("**      THAO TAC TREN CHUOI    **\n");
        printf("**    1. Nhap DSSV             **\n");
        printf("**    2. In DSSV               **\n");
        printf("**    3. Tim Kiem              **\n");
        printf("**    0. Thoát                 **\n");
        printf("*********************************\n");
        fflush(stdin);
         printf("\n \t\t     AN PHIM CHON: ");
         scanf("%d",&c);
         switch(c)
	}
}
