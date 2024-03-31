 #include <stdio.h>
 #include <conio.h>
 #include <stdlib.h>
int nhapmang(int a[50],int n)

{int i;
	 for (int i=0; i<n; i++)
   { printf ("\n nhap a [%d]=",i);
      scanf ("%d",&a[i]);
 
    }
}
int xuatmang(int a[50],int n) 

{ int i;

  for (i=0; i<n; i++)
 
 printf("%d\t",a[i]);

}
int timkiem  (int a[50], int n)
{
  int x, t=0;
  printf ("\n Nhap so can tim: ");
  scanf ("%d",&x);
  for (int i = 0; i < n; i++)
  {
  if (a[i] == x)  
       { 
        printf("\n %d o vi tri a[%d] ",x,i);
         t++;
       }
  }
 if (t==0)
   {
 	printf("Khong tim thay!");
   }
      else 
         {
 	         printf ("\n %d xuat hien %d lan!",x,t);
         } 
}
int kiemtra(int n) {
    if (n < 2) {
        return 0; 
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0; 
        }
    }
    return 1; 
}
void snt(int a[], int n) {
    printf("Vi tri cac snt:\n");
    for (int i = 0; i < n; i++) {
        if (kiemtra(a[i])) {
            printf("a[%d] ", i);
        }
    }
    printf("\n");
}

int  main()

{  int a[50], n,i ;
 printf ("\n Nhap so phan tu n= ");
 scanf ("%d",&n);
    nhapmang(a,n);
    printf (" Mang vua nhap la: \n");
     xuatmang(a,n);
      timkiem(a,n);
      snt(a,n);
      system("pause");
      return 0;
}


