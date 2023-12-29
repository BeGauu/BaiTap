#include<stdio.h>
#include<conio.h>
#include<string.h>
int tong(int n)
{
	int tinh;
	if (n==1){
		return (1);
	}else {
		tinh= n+tong(n-1);
	}return (tinh);
}
int main ()
{
	int i,n,tinhtong;
	printf ("Nhap mot so nguyen duong: ");
	scanf ("%d",&n);
	tinhtong= tong(n);
	printf ("\n Ting cac so tu 1 toi %d la: %d",n,tinhtong);
	return (0);
}
