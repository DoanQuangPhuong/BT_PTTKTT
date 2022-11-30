#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAXSIZE 100

struct DOVAT{
	char name[20];
	float gi,vi,Don_Gia;
	int PhuongAn;
};

void input1DV(DOVAT &dv);
void ouput1DV(DOVAT sv);
void inputDSDV(DOVAT dsdv[], int &n);
void ouputDSDV(DOVAT dsdv[], int n);
void sap_Xep_Giam_Dan_Theo_DonGia(DOVAT dsdv[], int n);
void lay_Do_Vat(DOVAT dsdv[], int n,float W);
void lay_Do_Vat_BienThe1(DOVAT dsdv[], int n,float W,int SL_YeuCau);
void lay_Do_Vat_BienThe2(DOVAT dsdv[], int n,float W);
void showMenu();
void suLi();

int main(){
	suLi();
	
	return 0;
}


void showMenu(){
	printf("\n*******************************************************");
	printf("\n*                          MENU                       *");
	printf("\n*******************************************************");
	printf("\n* 0 De Thoat Khoi Chuong Trinh                        *");
	printf("\n* 1 Nhap Xuat Danh Sach Do_Vat                        *");
	printf("\n* 2 Sap Xep Do_Vat theo Don Gia Giam Dam              *");
	printf("\n* 3 Lay_Do_Vat                                        *");
	printf("\n* 4 Lay_Do_Vat KHONG VUOT QUA So Luong cho phep       *");
	printf("\n* 5 Lay_Do_Vat Bien The 2                             *");
	printf("\n*******************************************************");
}

void suLi(){
	int n,luachon,SL_YeuCau;
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
				sap_Xep_Giam_Dan_Theo_DonGia(dsdv,n);
				break;
			}
			case 3:{
				printf("\n\tNhap Trong Luong W = ");scanf("%f", &W);
				lay_Do_Vat(dsdv,n,W);
				break;
			}
			case 4:{
				printf("\n\tTrong Luong W = ");scanf("%f", &W);
				printf("\n\tSo Luong Do_Vat khong vuot qua  = ");scanf("%d", &SL_YeuCau);
				lay_Do_Vat_BienThe1(dsdv,n,W,SL_YeuCau);
				break;
			}
			case 5:{
				printf("\n\tTrong Luong W = ");scanf("%f", &W);
				lay_Do_Vat_BienThe2(dsdv,n,W);
				break;
			}
		}
	}while(luachon != 0);
}

void input1DV(DOVAT &dv){
	printf("\n\tTen Do Vat  : ");
	fflush(stdin);
	gets(dv.name);
	printf("\n\tTrong Luong : ");scanf("%f", &dv.gi);
	printf("\n\tGia Tri : ");scanf("%f", &dv.vi);
}
void ouput1DV(DOVAT dv){
	printf("%-15s%5.2f\t\t%5.2f\t\t%5.2f\n",dv.name,dv.gi,dv.vi, float(dv.vi / dv.gi));

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
	printf("\n%-13s%-8s\t%-15s\t%-15s\n", "TenDV","Trong Luong","Gia Tri", "Don Gia");
	for(int i = 0;i < n;i++){
		ouput1DV(dsdv[i]);
	}
}
void swap(DOVAT &a, DOVAT &b){
	DOVAT temp = a;
	a = b;
	b = temp;
}

void sap_Xep_Giam_Dan_Theo_DonGia(DOVAT dsdv[], int n){
	printf("\n\tDanh Sach Do Vat sau khi duoc sap xep giam dan theo Don Gia ");
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			if(float(dsdv[i].vi / dsdv[i].gi) < float(dsdv[j].vi / dsdv[j].gi))
				swap(dsdv[i],dsdv[j]);
			else if(float(dsdv[i].vi / dsdv[i].gi) == float(dsdv[j].vi / dsdv[j].gi)){
				if(dsdv[i].vi < dsdv[j].vi)
					swap(dsdv[i] , dsdv[j]);
			}
		}
	}
	ouputDSDV(dsdv,n);
}

void lay_Do_Vat(DOVAT dsdv[], int n,float W){
	//Lay Gia tri vao bien PhuongAn
	for(int i = 0;i < n;i++){
		dsdv[i].PhuongAn = int(W / dsdv[i].gi);
		W -= (dsdv[i].PhuongAn * dsdv[i].gi);
	}
	//In ra Phuong An Thoa Man != 0 
	printf("\nVay lay : ");
	for(int i = 0;i < n;i++){
		if(dsdv[i].PhuongAn != 0){
			printf("%d%s ", dsdv[i].PhuongAn,dsdv[i].name);
		}
	}
	//Tinh Tong va In Ra Trong Luong Va Gia Tri Cua Phuong An Thoa Man
	float Sgi = 0,Svi = 0;
	for(int i = 0;i < n;i++){
		if(dsdv[i].PhuongAn != 0){
			Sgi += dsdv[i].PhuongAn*dsdv[i].gi;
			Svi += dsdv[i].PhuongAn*dsdv[i].vi;
		}
	}
	printf("\nTong Trong Luong Do Vat trong Balo Co The Lay La : %.2f\n", Sgi);
	printf("Tong Gia Tri Do Vat trong Balo Co The Lay La : %.2f\n", Svi);
}
void lay_Do_Vat_BienThe1(DOVAT dsdv[], int n,float W,int SL_YeuCau){
	//Lay Gia tri thoa man dieu kiem vao bien PhuongAn
	for(int i = 0;i < n;i++){
		dsdv[i].PhuongAn = int(W / dsdv[i].gi);
		if(dsdv[i].PhuongAn > SL_YeuCau)
		{
			dsdv[i].PhuongAn = SL_YeuCau;
		}
		W -= (dsdv[i].PhuongAn * dsdv[i].gi);
	}
	//In ra Phuong An Thoa Man
	printf("\nVay lay : ");
	for(int i = 0;i < n;i++){
		if(dsdv[i].PhuongAn != 0){
			printf("%d%s ", dsdv[i].PhuongAn,dsdv[i].name);
		}
	}
	//Tinh Tong va In Ra Trong Luong Va Gia Tri Cua Phuong An Thoa Man
	float Sgi = 0,Svi = 0;
	for(int i = 0;i < n;i++){
		if(dsdv[i].PhuongAn != 0){
			Sgi += dsdv[i].PhuongAn*dsdv[i].gi;
			Svi += dsdv[i].PhuongAn*dsdv[i].vi;
		}
	}
	printf("\nTong Trong Luong Do Vat trong Balo Co The Lay La : %.2f\n", Sgi);
	printf("Tong Gia Tri Do Vat trong Balo Co The Lay La : %.2f\n", Svi);
}
void lay_Do_Vat_BienThe2(DOVAT dsdv[], int n,float W){
	//Lay Gia tri thoa man dieu kiem vao bien PhuongAn
	for(int i = 0;i < n;i++){
		dsdv[i].PhuongAn = int(W / dsdv[i].gi);
		if(dsdv[i].PhuongAn > 1)
		{
			dsdv[i].PhuongAn = 1;
		}
		W -= (dsdv[i].PhuongAn * dsdv[i].gi);
	}
	//In ra Phuong An Thoa Man
	printf("\nVay lay : ");
	for(int i = 0;i < n;i++){
		if(dsdv[i].PhuongAn != 0){
			printf("%d%s ", dsdv[i].PhuongAn,dsdv[i].name);
		}
	}
	//Tinh Tong va In Ra Trong Luong Va Gia Tri Cua Phuong An Thoa Man
	float Sgi = 0,Svi = 0;
	for(int i = 0;i < n;i++){
		if(dsdv[i].PhuongAn != 0){
			Sgi += dsdv[i].PhuongAn*dsdv[i].gi;
			Svi += dsdv[i].PhuongAn*dsdv[i].vi;
		}
	}
	printf("\nTong Trong Luong Do Vat trong Balo Co The Lay La : %.2f\n", Sgi);
	printf("Tong Gia Tri Do Vat trong Balo Co The Lay La : %.2f\n", Svi);
}

