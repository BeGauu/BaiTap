#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
char s1[50];
char s2[50];

void nhap ()
{ 
   printf ("Nhap chuoi s1: ");
   gets (s1);
   printf ("\nNhap chuoi s2: ");
   gets (s2);
}
void xuat()
{ 
   printf ("\nChuoi s1: %s",s1);
   printf ("\nChuoi s2: %s ",s2);   
}
void xoakhtrang(char*s)
{ 
  int n,dem=0;
	n=strlen(s);
		for(int i=0;i<n;i++)
		{
			if((s[i]==' ')&&(s[i+1]==' '))
			{
				for(int j=i;j<n;j++)
				{
					s[j]=s[j+1];
				}
				n--;	
				i--;	
			}
		}
		dem++;
	printf("\nChuoi sau khi xoa khoang trang: ");
	for (int i=0;i<n;i++)
	{
		printf("%c",s[i]);
	}
}
void inhoa (char*s)
{ strlwr(s);
  s[0]=s[0]-32;
  for (int i=0; i<strlen(s); i++)
  { 
    if (s[i]==' '&& s[i+1]!=' ')
      s[i+1]=s[i+1]-32;
  }  
}
int demsolanxuathien(char *s1, char *s2) {
  int dem = 0;
  int ss2 = strlen(s2);
  for (int i = 0; i < strlen(s1); i++) {
    if (strncmp(s1 + i, s2, ss2) == 0) {
      dem++;
      i += ss2 - 1;
    }
  }
  return dem;
}
int demkitu(char *s1, char *s2)
{ int dem=0,s;
   char c;
   printf ("\n Nhap mot ky tu: ");
   scanf ("%c",&c);
   fflush(stdin);
   strupr(s1);
   for (int i=0;i<strlen(s1); i++)
   { if (s1[i]==toupper(c))
      dem++;
   }printf ("\nSo ky tu tu: %d",dem);
   
}


int main()
{ 
   nhap();
   xuat();
   xoakhtrang(s1);xoakhtrang(s2);
   inhoa(s1);inhoa(s2);
   xuat();
   printf("\nSo lan xuat hien cua chuoi S2 là: %d\n", demsolanxuathien(s1, s2));
   demkitu(s1);
   getch();
}
