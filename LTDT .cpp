#include<stdio.h>

#include<stdlib.h>

int a[10][10],n;

void docfile(){

	FILE *f;

	f=fopen("BTH2.txt", "r");

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

	for (int i=1; i<=n; i++){

	for (int j=1; j<=n; j++){

		printf(" %d ",a[i][j]);

	}

	printf("\n");

}

}

//Ham kiem tra phan tu co nho hon hoac bang 1 hay khong

int KT_phanTu(int a[10][10], int n){

	for(int i = 1; i <= n; i++){

		for(int j = 1; j <= n; j++){

			if(a[i][j] > 1){

				return 0; //lon hon 1 thi sai, tra 0

			}

		}

	}

	return 1; //dung het thi tra 1

}



//Kiem tra mang hai chieu co doi xung voi nhau hay khong

int KT_doiXung(int a[10][10], int n){

	for(int i = 1; i <= n; i++){

		for(int j = 1; j <= n; j++){

			if(a[i][j] != a[j][i] ){

				return 0;

			}

		}

	}

	return 1;

}

//Ham kiem tra xem duong cheo chinh co bang 0 hay khong

int KT_cheoChinh(int a[10][10], int n){

	for(int i = 1; i <= n; i++){

		if(a[i][i] != 0){

			return 0;

		}

	}

	return 1;

}



int main(){

	docfile();

	

	infile();

	if(KT_doiXung(a,n))

	{

		if(KT_cheoChinh(a,n)==0)

			printf("\n Gia do thi");

		else

		{

			if (KT_phanTu(a,n))

			{

				printf("\n Don do thi vo huong");

				exit(0);

			}

			else

			{			

				printf("\n Da do thi vo huong");

				exit(0);

			}

		}

	}

	else

	{

	

		if(KT_phanTu(a,n))

		{

		

			printf("\n Don do thi co huong");

			exit(0);

		}

		else

		{

		

			printf ("\n Da do thi co huong");

			exit(0);

		}

	}

}

