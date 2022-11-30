#include<stdio.h>
#include<conio.h>
int sumArr(int arr[100],int n);
int sumArr_DQ(int arr[100],int n);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void Quick_Sort(int *arr,int Left, int Right);
int BinarySearch(int arr[100], int n, int x);
int BinarySearch_DQ(int arr[100], int left , int right , int x);
void ouput(int arr[100], int n);
void Merge_English(int arr[], int L[] , int R[],int nL , int nR);
void MerSort_English(int arr[], int n);

int main(){
	int arr[] = {1,6,4,7,9,-1,2,4,7,-15,69,10,2,3,5};
	//So luong phan tu cua Mang arr[]
	int n = (int)(sizeof(arr) / sizeof(arr[0])),x;
	
	printf("\tSum = %d", sumArr(arr,n));
	printf("\tSum = %d", sumArr_DQ(arr,n));
	printf("\n\tSap xep tang dan theo thuat toan Merge sort : ");
	mergeSort(arr,0,n - 1);
	ouput(arr,n);
	
	printf("\n\tSap xep tang dan theo thuat toan Merge sort English : ");
	MerSort_English(arr,n);
	ouput(arr,n);
	
	printf("\n\tSap xep tang dan theo thuat toan Quick sort : ");
	Quick_Sort(arr,0,n - 1);
	ouput(arr,n);
	printf("\n\tNhap gia tri can tim kiem : ");scanf("%d", &x);
	//Tim Kiem Nhi Phan Khong De Quy
	if(BinarySearch(arr,n,x) == -1)
		printf("\n\tKhong tim thay gia tri trong arr");
	else
		printf("\n\tDa Tim Thay x tai vi tri arr[%d]", BinarySearch(arr,n,x));
	//Tim Kiem Nhi Phan De Quy
	if(BinarySearch_DQ(arr,0,n - 1,x) == -1)
		printf("\n\tKhong tim thay gia tri trong arr");
	else
		printf("\n\tDa Tim Thay x tai vi tri arr[%d]", BinarySearch_DQ(arr,0,n - 1,x));
	
	return 0;
}
//Tinh Tong Cac so trong arr
int sumArr(int arr[100],int n){
	int sum = 0;
	for(int i = 0;i < n;i++){
		sum += arr[i];
	}
	return sum;
}
int sumArr_DQ(int arr[100],int n){
	if(n == 1)
		return arr[0];
	return arr[n - 1] + sumArr_DQ(arr,n - 1);
}

void merge(int arr[], int l, int m, int r)  {  
    int i, j, k;  
    int n1 = m - l + 1;  
    int n2 = r - m;  
    
    /* create temp arrays */
    int L[n1], R[n2];  
  
    /* Copy data to temp arrays L[] and R[] */
    
    for (i = 0; i < n1; i++)  
        L[i] = arr[l + i];  
    for (j = 0; j < n2; j++)  
        R[j] = arr[m + 1 + j];  
        
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray  
    j = 0; // Initial index of second subarray  
    k = l; // Initial index of merged subarray  
    //Buoc apend gia tri tang dan vao arr[]
    while (i < n1 && j < n2) {  
        if (L[i] <= R[j]) {  
            arr[k] = L[i];  
            i++;  
        }  
        else {  
            arr[k] = R[j];  
            j++;  
        }  
        k++;  
    }  
  
    /* Copy the remaining elements of L[], if there  
    are any */
    //Nghia là Copy phan tu con lai cua L[] vao K
    while (i < n1) {  
        arr[k] = L[i];  
        i++;  
        k++;  
    }  
  
    /* Copy the remaining elements of R[], if there  
    are any */
    //Nghia là Copy phan tu con lai cua R[] vao K
    while (j < n2) {  
        arr[k] = R[j];  
        j++;  
        k++;  
    }  
}  

void mergeSort(int arr[], int l, int r)  { 
//Dieu Kien l < r : Kien Tra xem chung ta co den mang con nho nhat chi gom 1 Phan Tu Hay khong 
    if (l < r) {  
        // Same as (l+r)/2, but avoids overflow for  
        // large l and h  
        int m = l + (r - l) / 2;  
  
        // Sort first and second halves  
        mergeSort(arr, l, m);  
        mergeSort(arr, m + 1, r);  
  
        merge(arr, l, m, r);  
    }  
}  

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
//Ham Sap Xep Nhanh Quick Sort
void Quick_Sort(int *arr,int Left, int Right){
	if (Left >= Right) return;
	int i = Left, j = Right, Mid = (Left+Right)/2;
	int x = arr[Mid];
	do {
	while(arr[i] < x) 
		i++; // Lap cho den khi a[i] >= x
	while(arr[j] > x) 
		j--; // Lap cho den khi a[j] <= x
	if(i <= j) {
	if(i < j)
	swap(arr[i], arr[j]);
	i++;
	j--;
	}
	} while(i < j);
	Quick_Sort(arr, Left, j);//Phan hoach xep ben trai 
	Quick_Sort(arr, i, Right);//Phan hoach ben Phai
}

//Tim Kiem Nhi Phan

int BinarySearch(int arr[100], int n, int x){
	int left = 0,right = n - 1;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		if(arr[mid] == x)
			return mid;
		else if(arr[mid] > x)
		{
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	return -1;
}

int BinarySearch_DQ(int arr[], int left, int right, int x){
	if(left <= right){
		int mid = (left + right) / 2;
		if(arr[mid] == x)
			return mid;
		else if(arr[mid] > x)
			return BinarySearch_DQ(arr,0,mid - 1,x);
		else
			return BinarySearch_DQ(arr,mid + 1,right,x);
	}
	return -1;
	
}
void ouput(int arr[100], int n){
	for(int i = 0;i < n;i++){
		printf("%3d", arr[i]);
	}
}




void Merge_English(int arr[], int L[] , int R[],int nL , int nR){
	int i = 0 , j = 0 , k = 0;
	while(i < nL && j < nR){
		if(L[i] <= R[i])
		{
			arr[k++] = L[i++];
		}
		else
		{
			arr[k++] = R[j++];
		}
	}
	while(i < nL)
	{
		arr[k++] = L[i++];
	}
	while(j < nR)
	{
		arr[k++] = R[j++];
	}	
}

void MerSort_English(int arr[], int n){
	if(n < 2)
		return;
	int mid = n / 2 , L[mid] , R[n - mid];
	for(int i = 0;i < mid;i++)
	{
		L[i] = arr[i];
	}
	for(int j = mid;j < n;j++)
	{
		R[j - mid] = arr[j];
	}
	MerSort_English(L,mid);
	MerSort_English(R,n - mid);
	Merge_English(arr,L,R,mid,n - mid);	
}

