 #include <stdio.h>
 #include <conio.h>
void hoanvi(int &x, int &y);
 int main()
 {int a, b;
      printf("Nhap a="); 
	  scanf("%d",&a);
      printf("\nNhap b="); 
	  scanf("%d",&b);
               hoanvi(a,b); 
   printf( "Gia tri a hoanvi: %d\n", a ); 
      printf( "Gia tri b hoanvi: %d\n", b );
      return 0;

 }
void hoanvi(int &x, int &y )
 { int tam;
        tam=x;    x=y;     y=tam;
}
