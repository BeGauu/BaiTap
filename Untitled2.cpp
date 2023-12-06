#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char mssv[10];
    char hoten[50];
} sinhvien;

void doctep(char *tep);
void intep(char *tep);
void timkiemtep(char *tep);

int main()
{
    int c;
    for (;;)
    {   system("cls");
        printf("*********************************\n");
        printf("**      THAO TAC TREN CHUOI    **\n");
        printf("**    1. Nhap DSSV             **\n");
        printf("**    2. In DSSV               **\n");
        printf("**    3. Tim Kiem              **\n");
        printf("**    0. Thoat                 **\n");
        printf("*********************************\n");
        printf("\tAN PHIM CHON: ");
        scanf("%d", &c);
        fflush(stdin);
        if (c == 1)
        {
            doctep("sinhvien.txt");
        }
        else if (c == 2)
        {
            intep("sinhvien.txt");
        }
        else if (c == 3)
        {
            timkiemtep("sinhvien.txt");
        }
        else
            break;
    }
}

void doctep(char *tep)
{
    FILE *f;
    int n, i;
    sinhvien sv;
    f = fopen(tep, "wb");
    if (f == NULL)
    {
        printf("Loi mo tep!\n");
        return;
    }
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Sv thu %i\n", i);
        fflush(stdin);
        printf("- MSSV: ");
        scanf("%s", sv.mssv);
        fflush(stdin);
        printf("- Ho ten: ");
        scanf("%[^\n]", sv.hoten);
        fwrite(&sv, sizeof(sv), 1, f);
    }
    fclose(f);
    printf("\nBam phim bat ky de tiep tuc!\n");
    getchar();
}

void intep(char *tep)
{
    FILE *f;
    sinhvien sv;
    f = fopen(tep, "rb");
    if (f == NULL)
    {
        printf("Loi mo tep!\n");
        return;
    }
    printf("MSSV | Ho ten\n");
    while (fread(&sv, sizeof(sv), 1, f) == 1)
    {
        printf("%s | %s\n", sv.mssv, sv.hoten);
    }
    fclose(f);
    printf("\nBam phim bat ky de tiep tuc!\n");
    getchar();
}

void timkiemtep(char *tep)
{
    char Mssv[10];
    FILE *f;
    int Found = 0;
    sinhvien sv;
    fflush(stdin);
    printf("MSSV can tim: ");
    scanf("%s", Mssv);
    f = fopen(tep, "rb");
    if (f == NULL)
    {
        printf("Loi mo tep!\n");
        return;
    }
    while (fread(&sv, sizeof(sv), 1, f) == 1)
    {
        if (strcmp(sv.mssv, Mssv) == 0)
        {
            Found = 1;
            break;
        }
    }
    fclose(f);
    if (Found == 1)
    {
        printf("Tim thay SV co ma %s.\nHo ten la: %s", sv.mssv, sv.hoten);
    }
    else
    {
        printf("Tim khong thay sinh vien co ma %s", Mssv);
    }
    printf("\nBam phim bat ky de tiep tuc!\n");
    getchar();
}
