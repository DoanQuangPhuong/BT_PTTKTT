#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAXSIZE 100

struct DOVAT{
	char name[20];
	int gi,vi;
	int PhuongAn;
};

void input1DV(DOVAT &dv);
void ouput1DV(DOVAT sv);
void inputDSDV(DOVAT dsdv[], int &n);
void ouputDSDV(DOVAT dsdv[], int n);
void check(DOVAT dsdv[], int n,int W,int F[][100] , int X[][100]);
void Balo_QuyHoachDong(DOVAT dsdv[], int n,int W,int F[][100] , int X[][100],int &k, int &v);
void xuatPhuongAn(DOVAT dsdv[], int n);
void showMenu();
void suLi();
int main(){
	suLi();
	
	return 0;
}


void showMenu(){
	printf("\n**********************************************************");
	printf("\n*                          MENU                          *");
	printf("\n**********************************************************");
	printf("\n* 0 De Thoat Khoi Chuong Trinh                           *");
	printf("\n* 1 Nhap Xuat Danh Sach Do_Vat                           *");
	printf("\n* 2 LAY DO VAT TRONG BALO BANG PHUONG PHAP QUY HOACH DONG*");
	printf("\n**********************************************************");
}

void suLi(){
	int n,luachon,SL_YeuCau,v,k,F[100][100],X[100][100];
	int W;
	DOVAT dsdv[MAXSIZE];

	do{
		showMenu();
		do{
			printf("\nLua Chon Cua BAN La: ");scanf("%d", &luachon);
			if(luachon < 0)
				printf("\n\tLua Chon Khong Hop Le!!!");
		}while(luachon < 0);
		switch(luachon){
			case 1:{
				inputDSDV(dsdv,n);
				printf("\n\tDANH SACH DO VAT SAU KHI DUOC XUAT");
				ouputDSDV(dsdv,n);
				break;
			}
			case 2:{
				printf("\n\tNhap Trong Luong : ");scanf("%d", &W);
				Balo_QuyHoachDong(dsdv,n,W,F,X,k,v);
				check(dsdv,n,W,F,X);
				xuatPhuongAn(dsdv,n);
				break;
			}
			
		}
	}while(luachon != 0);
}

void input1DV(DOVAT &dv){
	printf("\n\tTen Do Vat  : ");
	fflush(stdin);
	gets(dv.name);
	printf("\n\tTrong Luong : ");scanf("%d", &dv.gi);
	printf("\n\tGia Tri : ");scanf("%d", &dv.vi);
}
void ouput1DV(DOVAT dv){
	printf("%-15s%3d\t\t%3d\n",dv.name,dv.gi,dv.vi);

}
void inputDSDV(DOVAT dsdv[], int &n){
	do{
		printf("Nhap so luong Do Vat : ");scanf("%d", &n);
		if(n <= 0)
			printf("\n\tVui long nhap lai!!!!");
	}while(n <= 0);
	for(int i = 0;i < n;i++){
		printf("\n\tDo Vat thu %d ", i + 1);
		input1DV(dsdv[i]);
	}
}
void ouputDSDV(DOVAT dsdv[], int n){
	printf("\n%-13s%-8s\t%-15s\n", "TenDV","Trong Luong","Gia Tri");
	for(int i = 0;i < n;i++){
		ouput1DV(dsdv[i]);
	}
}
void swap(DOVAT &a, DOVAT &b){
	DOVAT temp = a;
	a = b;
	b = temp;
}

void Balo_QuyHoachDong(DOVAT dsdv[], int n,int W,int F[][100] , int X[][100],int &k, int &v){
	//X[k,V] luu tru So Luong Do Vat Duoc Chon
	//F[k,V] luu tru Tong Gia k Do Vat duoc chon ung voi trong luong cua BALO la V
	int xk, yk, Fmax, Xmax;
	for(v = 0;v <= W;v++){
		//Lap day Dong dau tien cua 2 MANG
		X[0][v] = v / dsdv[0].gi;
		F[0][v] = X[0][v] * dsdv[0].vi;
	}
	
	//Lap dau cac Hang con lai
	for(k = 1;k < n;k++)
	{
		X[k][0] = 0;
		F[1][0] = 0;	
		for(v = 0;v <= W;v++)
		{
			Fmax = F[k - 1][v];
			Xmax = 0;
			yk = v / dsdv[k].gi;
			for(xk = 0;xk <= yk;xk++)
			{
				if(F[k - 1][v - xk * dsdv[k].gi] + xk * dsdv[k].vi > Fmax)
				{
					Fmax = F[k - 1][v - xk * dsdv[k].gi] + xk *dsdv[k].vi;
					Xmax = xk;
				}
				F[k][v] = Fmax;
				X[k][v] = Xmax;	
			}
		}
	}
}


void check(DOVAT dsdv[], int n,int W,int F[][100] , int X[][100]){
	int k,v;
	v = W;
	for(k = n - 1;k >= 0;k--){
		if(X[k][v] > 0)
		{
			dsdv[k].PhuongAn = X[k][v];
			v = v - X[k][v] * dsdv[k].gi;
		}
	}
}

void xuatPhuongAn(DOVAT dsdv[], int n){
	printf("\n\t\tPHUONG AN : ");
	int Sumgi = 0,Sumvi = 0;
	for(int i = 0;i < n;i++){
		if(dsdv[i].PhuongAn > 0){
			printf("%d%-5s", dsdv[i].PhuongAn,dsdv[i].name);
			Sumgi += dsdv[i].PhuongAn * dsdv[i].gi;
			Sumvi += dsdv[i].PhuongAn * dsdv[i].vi;
		}
	}
	printf("\nTong Trong Luong : %d ", Sumgi);
	printf("\nTong Gia tri : %d ", Sumvi);
}



