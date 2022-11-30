#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAXSIZE 100
typedef int Itemtype;
void nhapMang2C(Itemtype arr[][MAXSIZE], int &n, int &m);
void xuatMang2C(Itemtype arr[][MAXSIZE], int n, int m);
void nhapMang2_Vuong(Itemtype arr[][MAXSIZE], int &n);
void xuatMang2_Vuong(Itemtype arr[][MAXSIZE], int n);
void Matrit_Mul(Itemtype arr[][MAXSIZE], Itemtype brr[][MAXSIZE], int n , int m , int l, int k);
void MatMul(Itemtype *arr , Itemtype *brr, Itemtype *crr, int n);
void xuLy();
void showMenu();

int main(){
	xuLy();
	
	
	
	return 0;
}
void nhapMotSoNguyen(int &n){
	do{
	scanf("%d", &n);
	if(n < 0)
		printf("\nVui long nhap lai n > 0!!!");
	}while(n < 0);
}

void nhapMang2C(Itemtype arr[][MAXSIZE], int &n, int &m){
	do{
		printf("Nhap so Hang: ");scanf("%d", &n);
		printf("\nNhap so Cot: ");scanf("%d", &m);
		if(n <= 0 || m <= 0)
			printf("\nKhong hop le vui long nhap lai!!!");
	}while(n <= 0 || m <= 0);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			printf("\narr[%d][%d] = ", i,j);scanf("%d", &arr[i][j]);
		}
}
void nhapMang2_Vuong(Itemtype arr[][MAXSIZE], int &n){
	do{
		printf("Nhap so Hang: ");scanf("%d", &n);
		if(n <= 0)
			printf("\nKhong hop le vui long nhap lai!!!");
	}while(n <= 0);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++){
			printf("\narr[%d][%d] = ", i,j);scanf("%d", &arr[i][j]);
		}
}
void xuatMang2_Vuong(Itemtype arr[][MAXSIZE], int n){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}
}
void xuatMang2C(Itemtype arr[][MAXSIZE], int n, int m){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}
}

void Matrit_Mul(Itemtype arr[][MAXSIZE], Itemtype brr[][MAXSIZE], int n , int m , int l, int k){
	int crr[MAXSIZE][MAXSIZE];
	for(int i = 0;i < n;i++){
		for(int j = 0 ;j < m;j++){
			crr[i][j] = 0;
			for(int k = 0;k < m;k++){
				crr[i][j] = crr[i][j] + arr[i][k] * brr[k][j];
			}
		}
	}
	xuatMang2C(crr,n,m);
}

void MatMul(Itemtype *arr , Itemtype *brr, Itemtype *crr, int n){
	if(n == 1)
		(*crr) += (*arr) * (*brr);
	else{
		MatMul(arr,brr,crr,n/4);
		MatMul(arr,brr + (n / 4),crr + (n / 4),n/4);
		MatMul(arr + 2 *(n / 4), brr , crr + 2*(n / 4) , n/4);
		MatMul(arr + 2 *(n / 4), brr + (n / 4) , crr + 3 *(n / 4) , n/4);
		MatMul(arr + (n / 4), brr + 2*(n/4) , crr , n/4);
		MatMul(arr + (n / 4), brr + 3*(n/4), crr + (n / 4) , n/4);
		MatMul(arr + 3 *(n / 4), brr  + 2 *(n / 4), crr + 2*(n / 4) , n/4); 
		MatMul(arr + 3 *(n / 4), brr + 3 *(n/4), crr + 3*(n / 4) , n/4);
	}
}
//===============================================================================================================
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void reverse(int a[], int n){//Dao Nguoc Mang
//	int left = 0, right = n - 1;
//	while(left < right){
//		int temp = a[left];
//		a[left] = a[right];
//		a[right] = temp;
//		left++;right--;
//	}
	for(int i = 0; i < n / 2 ; i++){
		swap(a[i],a[n - 1- i]);
	}
}


void add(char a[], char b[]){
	int len1 = strlen(a),len2 = strlen(b),n = 0;
	int x[len1],y[len1],z[len1 + 1];
	for(int i = 0;i < len1;i++)
		x[i] = a[i] - '0';//Chuyen Ki tu Ve dang So
		
	for(int i = 0;i < len2;i++)
		y[i] = b[i] -'0';//Chuyen Ki tu Ve dang So
		
	reverse(x,len1);//Dao mang
	reverse(y,len2);//Dao mang
	for(int i = len2;i < len1;i++){
		y[i] = 0;
	}
	int nho = 0;
	for(int i = 0;i < len1;i++)
	{
		int temp = x[i] + y[i] + nho;
		z[n++] = temp % 10; //VD : 15 thì temp = 5 , Nêu 7 thi temp = 7
		nho = temp/10; // VD : 15 thi nho = 1, 7 thì nho = 0
	}
	if(nho != 0)
		z[n++] = nho;
	for(int i = n - 1;i >=0;i--)
	{
		printf("%d", z[i]);
	}
}


/*
Hieu Hai Chuoi Cho Lon Nho Hon 100 Ki Tu So
*/


void sub(char a[], char b[]){
	int len1 = strlen(a),len2 = strlen(b),n = 0;
	int x[len1],y[len1],z[len1 + 1];
	for(int i = 0;i < len1;i++)
		x[i] = a[i] - '0';//Chuyen Ki tu Ve dang So
	for(int i = 0;i < len2;i++){
		y[i] = b[i] -'0';//Chuyen Ki tu Ve dang So
	}
	reverse(x,len1);//Dao mang
	reverse(y,len2);//Dao mang
	for(int i = len2;i < len1;i++){
		y[i] = 0;
	}
	int nho = 0;
	for(int i = 0;i < len1;i++)
	{
		int temp = x[i] - y[i] - nho;
		if(temp < 0) //am
		{
			z[n++] = 10 + temp;
			nho = 1;//Tang nho len 1 
		}
		else
		{
			z[n++] = temp;
			nho = 0;
		}
	}
	int ok = 0;
	for(int i = n - 1;i >= 0;i--){
		if(ok == 0 && z[i] != 0){
			ok = 1;
		}
		if(ok != 0)
			printf("%d",z[i]);
	}
	if(ok == 0)
		printf("0");
}

void showMenu(){
	printf("\n*********************************************************");
	printf("\n*                          MENU                         *");
	printf("\n*********************************************************");
	printf("\n* 0 De Thoa khoi chuong trinh                           *");
	printf("\n* 1 Nhap Xuat Mang 2 Chieu                              *");
	printf("\n* 2 Nhan 2 Matrix NotDQ                                 *");
	printf("\n* 3 Nhan 2 Matrix  DQ                                   *");
	printf("\n* 4 Hieu 2 so nguyen lon                                *");
	printf("\n* 5 Tong 2 so nguyen lon                                *");
	printf("\n*********************************************************");	
}
void xuLy(){
	Itemtype arr[MAXSIZE][MAXSIZE],brr[MAXSIZE][MAXSIZE],crr[MAXSIZE][MAXSIZE],n,m,l,k;
	int luachon;
	do{
		    showMenu();
			printf("\nSu lua chon cua ban la : ");
	        nhapMotSoNguyen(luachon);
		switch(luachon){
			case 1:{
				nhapMang2C(arr,n,m);
				printf("Mang sau khi duoc tao : \n");
				xuatMang2C(arr,n,m);
				break;
			}
			case 2:{
				
				nhapMang2C(brr,l,k);
				printf("Matrix brr  \n");
				xuatMang2C(brr,l,k);
				if(m == l){
					printf("Nhan 2 ma trit  \n");
					Matrit_Mul(arr,brr,n,m,l,k);
				}
				else{
					printf("2 Ma Tran Nay Khong The Nhan Duoc Voi Nhau !!!");
				}
				break;
			}
			case 3:{
			
				nhapMang2_Vuong(arr,n);
				printf("\nMaTrix Sau Khi Duoc Arr[] sau khi duoc tao \n");
				xuatMang2_Vuong(arr,n);
				nhapMang2_Vuong(brr,n);
				printf("\nMaTrix Sau Khi Duoc Brr[] sau khi duoc tao \n");
				xuatMang2_Vuong(brr,n);
				printf("Nhan 2 Ma Tran  \n");
				MatMul(arr,brr,crr,n);
				xuatMang2_Vuong(crr,n);
				
				break;
			}
			case 4:{
				char a[1000],b[1000];
				printf("\n\tChuoi 1 : ");scanf("%s", &a);
				printf("\n\tChuoi 2 : ");scanf("%s", &b);
				int n = strlen(a),n1 = strlen(b);
				if(n >= n1){
				printf("Hieu Chuoi = ");
				sub(a,b);
				}
				else
				{
					printf("Hieu Chuoi = ");
					sub(b,a);
				}
				break;
			}
			case 5:{
				char a[1000],b[1000];
				printf("\n\tChuoi 1 : ");scanf("%s", &a);
				printf("\n\tChuoi 2 : ");scanf("%s", &b);
				int n = strlen(a),n1 = strlen(b);
				if(n >= n1){
				printf("Tong Chuoi = ");
				add(a,b);
				}
				else
				{
					printf("Tong Chuoi = ");
					add(b,a);
				}
				break;
			}
		}
	}while(luachon != 0);	
}

