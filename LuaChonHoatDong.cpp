#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAXSIZE 100

struct TIME{
	int Si,Ei;
};
struct HOATDONG{
	char tenHD[100];
	TIME t;
	char ds[100][100];
};

void input1HD(HOATDONG &hd);
void ouput1HD(HOATDONG hd);
void inputDSHD(HOATDONG dshd[], int &n);
void ouputDSHD(HOATDONG dshd[], int n);
void sapXepThoiGianStartAndEndTandDan(HOATDONG dshd[], int n);
void SuLiBtHoatDong(HOATDONG dshd[], int n);
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
	printf("\n* 1 Nhap Xuat Danh Sach Danh Sach Hoat Dong           *");
	printf("\n* 2 Sap Xep va dua ra Danh sach hoat dong             *");
	printf("\n*******************************************************");
}

void suLi(){
	int n,luachon;
	float W;
	HOATDONG dshd[MAXSIZE];

	do{
		showMenu();
		do{
			printf("\nLua Chon Cua BAN La: ");scanf("%d", &luachon);
			if(luachon < 0)
				printf("\n\tLua Chon Khong Hop Le!!!");
		}while(luachon < 0);
		switch(luachon){
			case 1:{
				inputDSHD(dshd,n);
				printf("\n\tDANH SACH DO VAT SAU KHI DUOC XUAT");
				ouputDSHD(dshd,n);
				break;
			}
			case 2:{
				printf("\n\tDanh sach sau khi sap xep \n");
				sapXepThoiGianStartAndEndTandDan(dshd,n);
				ouputDSHD(dshd,n);
				SuLiBtHoatDong(dshd,n);
				break;
			}
			
		}
	}while(luachon != 0);
}

void input1HD(HOATDONG &hd){
	printf("\nTen Hoat Dong  : ");
	fflush(stdin);
	gets(hd.tenHD);
	printf("Start : ");scanf("%d", &hd.t.Si);
	printf("Finish : ");scanf("%d", &hd.t.Ei);
}
void ouput1HD(HOATDONG hd){
	printf("%-15s%10d\t\t%5d\n",hd.tenHD,hd.t.Si,hd.t.Ei);

}
void inputDSHD(HOATDONG dshd[], int &n){
	do{
		printf("Nhap so luong Hoat Dong : ");scanf("%d", &n);
		if(n <= 0)
			printf("\n\tVui long nhap lai!!!!");
	}while(n <= 0);
	for(int i = 0;i < n;i++){
		printf("\n\tHoat Dong thu %d ", i + 1);
		input1HD(dshd[i]);
	}
}
void ouputDSHD(HOATDONG dshd[], int n){
	printf("\n%-20s%-10s\t\t%-50s\n", "TenHV","Start time","End time");
	for(int i = 0;i < n;i++){
		ouput1HD(dshd[i]);
	}
}
void swapNumber(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void swap(HOATDONG &a, HOATDONG &b){
	HOATDONG temp = a;
	a = b;
	b = temp;
}

void sapXepThoiGianStartAndEndTandDan(HOATDONG dshd[], int n){
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			if(dshd[i].t.Ei > dshd[j].t.Ei)
				swap(dshd[i] , dshd[j]);
		}
	}
}

void SuLiBtHoatDong(HOATDONG dshd[], int n){
	//Chon Cuoc hop dau tien vao danh sach
	strcpy(dshd[0].ds[0],dshd[0].tenHD);
	int k = 0;
	//Do dai ban dau cua ds
	int len = 1;
	for(int i = 1;i < n;i++){
		//Neu tg bat dau phan tu sau >= tg ket thuc phan tu truoc thi Dua ten cuoc hop vao danh sach
		if(dshd[i].t.Si >= dshd[k].t.Ei)
		{
			strcpy(dshd[len].ds[len],dshd[i].tenHD);
			len++;
			//Gan lai chi so vua duoc thuc hien-> Tiep tuc duyet danh sach
			k = i;
		}
	}
	//In ra danh sach vua duoc coppy vao ds[]
	printf("\t\tDANH SACH HOAT DONG : ");
	for(int i = 0;i < len;i++){
		printf("%-5s",dshd[i].ds[i]);
	}
}




