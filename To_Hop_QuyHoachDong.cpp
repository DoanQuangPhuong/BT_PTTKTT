#include<stdio.h>
#include<conio.h>
void showMenu();
void suLi();
long long mod = 1e9 + 7;
int TopHopQuyHoachDong_2C(int n , int k);
int main(){
	suLi();
	return 0;
}





int ToHopkCn_DQ(int n, int k){
	if(k == 0 || k == n)
		return 1;
	return ToHopkCn_DQ(n - 1,k - 1) + ToHopkCn_DQ(n - 1,k);
}

//To Hop Theo Quy Tac QUY HOACH DONG Mang 1C
int TopHopQuyHoachDong(int n , int k){
	int C[n + 1],p1,p2;
	C[0] = C[1] = 1;
	for(int i = 2;i <= n;i++){//
		p1 = C[0];
		for(int j = 1;j < i;j++){//3 4
			p2 = C[j];
			C[j] = p1 + p2;
			p1 = p2;
		}
		C[i] = 1;
	}
	return C[k];
}


int TopHopQuyHoachDong_2C(int n , int k){
	int C[n + 1][k + 1];
	C[0][0] = 1;
	for(int i = 1;i <= n;i++){
		C[i][0] = 1;
		C[i][i] = 1;
		for(int j = 1;j < i;j++){
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			//C[i][j] %= mod;//Tranh tran so [Co hay khong khong bt]
		}
	}
	return C[n][k];
}
void showMenu(){
	printf("\n");
	printf("******************************************************\n");
	printf("*                     MENU                           *\n");
	printf("******************************************************\n");
	printf("*Nhan 0 de ket thuc chuong trinh                     *\n");
	printf("*Nhan 1 To Hop De Quy                                *\n");
	printf("*Nhan 2 To Hop Quy Hoach Dong Mang 1C                *\n");
	printf("*Nhan 3 To Hop Quy Hoach Dong Mang 2C                *\n");
	printf("******************************************************\n");
}

void suLi(){
	int luachon,n,k;
	do{
		showMenu();
		printf("Lua Chon Cua Ban La : ");scanf("%d", &luachon);
		switch(luachon){
			case 1:{
				printf("\nN = ");scanf("%d", &n);
				do{
					printf("\nK = ");scanf("%d", &k);
					if(k < 0 || k > n)
						printf("\n\tKHONG HOP LE !VUI LONG NHAP LAI !!!");
				}while(k < 0 || k > n);
				printf("\n\tTo Hop %dC%d = %d", k,n, ToHopkCn_DQ(n,k));
				break;
			}
			case 2:{
				printf("\n\tTo Hop QUY HOACH DONG 1C %dC%d = %d", k,n, TopHopQuyHoachDong(n,k));
				break;
			}
			case 3:{
				printf("\n\tTo Hop QUY HOACH DONG 2C %dC%d = %d", k,n, TopHopQuyHoachDong_2C(n,k));
				break;
			}
		}
		
	}while(luachon != 0);
}

