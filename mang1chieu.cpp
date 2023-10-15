 #include <stdio.h>
 #include <conio.h>
//void sapxep(int a[50],int &n);
int nhapmang(int a[50],int n);
void xuatmang(int a[50],int n);

int  main()

{ int a[50], n;

   printf("Nhap so pt mang");

    scanf("%d",&n);

    nhapmang(a,n);


   //xuatmang(a,n);

    getch();

}


int nhapmang(int a[50],int n)

{ int i,n;

for (i=0; i<n; i++)

printf("\nNhap a[%d]= ",i);

scanf("%d",&a[i]);

}
/*void xuatmang(int a[50],int n)

{ int i;

    for (i=0; i<n; i++)

       printf("%d\t",a[i]);
}*/


