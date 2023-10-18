 #include <stdio.h>
 #include <conio.h>
int sapxep(int a[50],int &n);
int nhapmang(int a[50],int n);
int xuatmang(int a[50],int n);
int timmax (int a[50],int n);
int tinhtich(int a[50],int n);
int sapxep (int a[50],int n);
int songuyento (int p);
int tinhtong (int a[50], int n);
int vitri (int a[], int n);
int  main()

{  int a[50], n,i ;
 printf ("\n Nhap so phan tu n= ");
 scanf ("%d",&n);
    nhapmang(a,n);
    printf (" Mang vua nhap la: \n");
     xuatmang(a,n);
     printf("\n Gia tri lon nhat trong mang: \n %d", timmax(a, n));
     printf("\n Tich cac phan tu trong mang: \n %d",tinhtich(a,n));
     vitri(a,n); 
     printf ("\n Mang vua sap xep: ");
     sapxep(a,n);
     xuatmang(a,n)
    chen (a,n);
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
int songuyento(int p) 
{
    int i,dem =0;
    for(i=1; i<p; i++) {
        if(p%i==0)
            dem++;

        if(dem==2)
            return 1;
        else
            return 0;
    }
}
int tinhtong(int a[50],int n) 
{
    int i, tong=0;
    for (i=0; i<n; i++)
	{
          if (songuyento (a[i])==1)
		
            tong=tong + a[i];
        
    }
    return tong;
	}

int vitri (int a[], int n)
{
  int tk;
  printf ("\n Nhap so can tim: ");
  scanf ("%d",&tk);
  for (int i = 0; i < n; i++)
  {
  if (a[i] == tk)  
  printf("Phan tu thu %d ", i);
   else   
    printf ("\n Phan khong co trong mang ! ");	
  }
getch();
}

int  sapxep(int a[50],int n)
{ int tam;
    for (int i=0; i<n–1; i++)
      for (int j=i+1; j<n; j++)
     if (a[i] > a[j])
   { tam=a[i];
        a[i]=a[j];
         a[j]=tam; 
   }
}
int  chen(int a[], int n)
{
    int x;
    printf("\nNhap vi tri muon them:");
    scanf("%d", &x);
    int y;
    printf("\nNhap phan tu muon them:");
    scanf("%d", &y);
    if(x<=0)
    {
        x=0;
    }else if(x>=n)
	 {
        x=n;
    }
    for(int i=n; i>x ; i--)
    {
        a[i] = a[i-1];        
    }
    a[x]=y;
    n++;
    printf("\nMang sau khi them la:\n");
    xuatmang(a,n);
}
