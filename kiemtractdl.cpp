#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int a[100],n;

void hoanvi(int &x, int &y)
{
	int t=x;
	    x=y;
	    y=t;
}
void nhap(int a[],int n)
{       
	for(int i=1;i<=n;i++)
    {
		printf("\n Nhap a[%d]=",i);
		scanf("%d",&a[i]);
	}
}

void xuat(int a[],int n)
{ 
	for(int i=1;i<=n;i++)
	printf("%4d",a[i]);
}

void BubleSort(int a[],int n)// sx noi bot
{
	int i,j;
	for(i=1;i<n;i++)
		for(j=n;j>i;j--)
		if(a[j]>a[j-1])
		hoanvi(a[j],a[j-1]);
}

int main()
{	int x;
	printf(" Nhap so phan tu:");
	scanf("%d",&n);
	nhap(a,n);
	printf("\n Day so da nhap la:");
	xuat(a,n);
	BubleSort(a,n);
	printf("\n Day so sau khi sap xep: ");
	xuat(a,n);
	return 0;
}
