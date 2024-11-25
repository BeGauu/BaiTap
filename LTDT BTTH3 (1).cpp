#include <iostream> 
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
using namespace std;
int a[10][10],n,d[10],x;

void docfile(){
	FILE *f;
	f=fopen("bt2.txt", "r");
	if (f==NULL){
		printf(" Khong co tap tin \n");
	}
	else{
		fscanf(f,"%d",&n);
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				fscanf(f,"%d", &a[i][j]);
			}
		}
	}
	fclose(f);
}
void infile(){
	for (int i=1; i<=n; i++)
	{
	for (int j=1; j<=n; j++)
	   {
		printf(" %d ",a[i][j]);
	   }
	     printf("\n");
    }
}

int dfs(int x){

	stack <int> s;
	s.push(x);
	while (!s.empty()){
	   int kq=s.top();
	   s.pop();
	   if (d[kq]==0){
	   printf ("%d ",kq);
	   d[kq]=-1;
	   }
	   for (int y=n; y>=1;y--)
	   if (a[kq][y]!=0 && d[y]==0){
	   s.push(y);}
	}

}

int main(){
	
	docfile();
	infile();
	for (int i=1; i<=n; i++){
	d[i]=0;}
	printf ("Dinh can duyen: ");
	scanf ("%d" ,&x);
	
	dfs(x);
return 0;
}
