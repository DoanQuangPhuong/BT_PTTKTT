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
typedef int TABLE[10][100];
void input1DV(DOVAT &dv);
void ouput1DV(DOVAT sv);
void inputDSDV(DOVAT dsdv[], int &n);
void ouputDSDV(DOVAT dsdv[], int n);
void InRaTenDVluaChon(DOVAT dsdv[], int n,int best[MAXSIZE],int W);
void CountSoLuongDoVat(DOVAT dsdv[], int n, int best[MAXSIZE],int W,int selects[MAXSIZE]);
void ouputSelects(DOVAT dsdv[], int n,int selects[MAXSIZE]);
void Dynamicprograming(DOVAT dsdv[], int n, float W	, int cost[MAXSIZE], int best[MAXSIZE],int selects[MAXSIZE]);
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
	int n,luachon,cost[MAXSIZE],best[MAXSIZE],selects[MAXSIZE];
	float W;
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
				printf("\n\tTrong Luong :");scanf("%f", &W);
				Dynamicprograming(dsdv,n,W,cost,best,selects);
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

//In ra ten ma gia tri best lua tru gia tri >= 0, tuk != -1
void InRaTenDVluaChon(DOVAT dsdv[], int n,int best[MAXSIZE],int W){
	for(int i = 0;i <= W;i++){
		if(best[i] >= 0)
			printf("%s  ",dsdv[best[i]].name);
		else
			printf("%c  ",'-');
	}
}

//Dem so Luong do vat duoc chon lua vao mang selects[]
void CountSoLuongDoVat(DOVAT dsdv[], int n, int best[MAXSIZE],int W,int selects[MAXSIZE]){
	int weight = W;
	//Gan Tat ca Mang selects == 0
	for(int i = 0;i < n;i++)
		selects[i] = 0;
	while(weight > 0)
	{
		int j = best[weight];
		if(j >= 0)
		{
			selects[j]++;
			weight -= dsdv[j].gi;
		}
		else
			weight--;
	}
}

//XUAT SO LUONG DO VAT CUNG VS TEN TUONG UNG MOI DO VAT DUOC CHON
void ouputSelects(DOVAT dsdv[], int n,int selects[MAXSIZE]){
	printf("\n\tDANH SACH CHON DO VAT : ");
	int sumGi = 0,sumVi = 0;
	for(int i = 0;i < n;i++){
		if(selects[i] > 0)
		{
			printf("%d%s\t",selects[i],dsdv[i].name);
			sumGi += selects[i] * dsdv[i].gi;
			sumVi += selects[i] * dsdv[i].vi;
		}
	}
	printf("\n\tTONG TRONG LUONG : %d",sumGi);
	printf("\n\tTONG GIA TRI : %d",sumVi);
}

void Dynamicprograming(DOVAT dsdv[], int n, float W	, int cost[MAXSIZE], int best[MAXSIZE],int selects[MAXSIZE]){
	//Khoi tao tat ca mang cost = 0 && ALL best = -1
	for(int i = 0;i <= W;i++)
	{
		cost[i] = 0;
		best[i] = -1;
	}
	for(int j = 0;j < n;j++){
		for(int i = 1;i <= W;i++)
			if(i - dsdv[j].gi >= 0)
				if(cost[i] < (cost[i - dsdv[j].gi] + dsdv[j].vi))
				{
					cost[i] = cost[i - dsdv[j].gi] + dsdv[j].vi;
					best[i] = j;
				}
	}
	
	
	for(int i = 0;i <= W;i++){
		printf("%-4d", cost[i]);
	}
	printf("\n");
	InRaTenDVluaChon(dsdv,n,best,W);

	printf("\n");
	CountSoLuongDoVat(dsdv,n,best,W,selects);
	
	ouputSelects(dsdv,n,selects);


}




