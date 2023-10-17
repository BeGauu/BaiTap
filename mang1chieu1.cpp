 #include <stdio.h>
 #include <conio.h>
int sapxep(int a[50],int &n);
int nhapmang(int a[50],int n);
int xuatmang(int a[50],int n);
int timmax (int a[50],int n);
int tinhtich(int a[50],int n);
int sapxep (int a[50],int n);
int  main()

{  int a[50], n,i ;
 printf ("\n Nhap so phan tu n= ");
 scanf ("%d",&n);
    nhapmang(a,n);
    printf (" Mang vua nhap la: \n");
     xuatmang(a,n);
     printf("\n Gia tri lon nhat trong mang: \n %d", timmax(a, n));
     printf("\n Tich cac phan tu trong mang: \n %d",tinhtich(a,n));
     sapxep(a,n);
     xuatmang(a,n)
    return 0;
}


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
int timmax(int a[50],int n)
{
   int max=a[0];
   for (int i=0; i<n ;i++)
     
	    if (max < a[i])
	    max=a[i];
	    return max;	 
}
int tinhtich(int a[50],int n)
{ int tich=1;
    for (int i=0; i<n; i++)
    tich=tich*a[i];
    return tich;
}
int  sapxep(int a[50],int n)

{ int tam;

    for (int i=0; i<n–1; i++)
{
      for (j=i+1; j<n; j++)

     if (a[i] > a[j])

   { tam=a[i];
        a[i]=a[j];
         a[j]=tam; 
   }
 }
}
