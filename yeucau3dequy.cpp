#include "stdio.h"
#include "stdlib.h"
 int main()
 {
 	int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
 	int m=3;
 	FILE *fp;
 	char path[50];
 	printf("\nNhap duong dan: ");
 	fflush(stdin);
 	gets(path);
 	
 	   fp=fopen(path,"wt");
 	   if(fp==NULL)
 	   {
 	   	 printf("\nLoi mo file");
 	   	 exit(0);
 	   }
 	   else
 	   {
 	   	fprintf(fp,"So dong, cot la %d\n",m);
 	   	for (int i=0; i<m; i++)
 	   	{
 	   		for(int j=0; j<m; j++)
 	   		{
 	   			fprintf(fp,"%3d",a[i][i]);
 	   		}
 	   		fprintf(fp,"\n");
 	   	}
 	   	fclose(fp);
 	   }
 }
