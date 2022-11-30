
#include <stdio.h>
#include<conio.h>

int linear_Search(int arr[100], int n,int x){
	for(int i = 0;i < n;i++)
	{
		if(arr[i] == x)
			return i;
	}
	return -1;
}

int BinarySearch(int arr[100], int n, int x){
	int left = 0,right = n - 1;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		if(arr[mid] == x)
			return mid;
		else if(arr[mid] > x)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

void swap(int &a , int &b){
	int temp = a;
	a = b;
	b = temp;
}

void ouput(int arr[100], int n){
	for(int i = 0;i < n;i++){
		printf("%4d", arr[i]);
	}
}

void Interchangesort(int arr[100], int n){
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			if(arr[i] > arr[j])
				swap(arr[i],arr[j]);
		} 
	}
	ouput(arr,n);
}

void selectionsort(int arr[100], int n){
	for(int i = 0;i < n - 1;i++){
		int min = i;
		for(int j = i + 1;j < n;j++){
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		swap(arr[min],arr[i]);
	}
	ouput(arr,n);
}

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
//Thuat toan sap xep noi bot
void Bubble_Sort(int arr[100],int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = n - 1; j > i; j--){//Duyet tat ca cac phan tu truoc i
			if(arr[j] < arr[j - 1]){//Kiem tra phan tu sau vs phan tu truoc no
				swap(arr[j] , arr[j - 1]);//Neu thoa dieu kien thì hoan doi hai phan tu ke
											//Nhau theo chieu xuoi
			}
		}
	}
	ouput(arr,n);
}

void merge(int arr[], int l, int m, int r){  
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

void mergeSort(int arr[], int l, int r)  
{  
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

void minMax_divide_conquer(int arr[], int l, int r,int *max,int *min,int *newMax,int *newMin){
	if(l == r){
		*max = arr[l];
		*min = arr[r];
	}
	else if(l == r - 1){
		if(arr[l]< arr[r])
		{
			*max = arr[r];
			*min = arr[l];
		}
		else{
			*max = arr[l];
			*min = arr[r];
		}
	}
	else{
		int mid = (l + r) / 2;
		minMax_divide_conquer(arr,l,mid,max,min,newMax,newMin);
		minMax_divide_conquer(arr,mid + 1,r,max,min,newMax,newMin);
		
		if(*max < *newMax)
			max = newMax;
		if(min > newMin)
			min = newMin;
		
	}
}
int main(){
	int n = 10;
	int arr[100] = {1,5,6,9,10,12,8,100,12,8};
//	printf("\nX = %d", linear_Search(arr,n,5));
//	printf("\nX = %d", BinarySearch(arr,n,12));
	
	//printf("Mang sau khi duoc sap xep tang dan : ");
	//Interchangesort(arr,n);
	
//	printf("Mang sau khi duoc sap xep tang dan : ");
//	selectionsort(arr,n);
	
	
//	Quick_Sort(arr,0,5);
//	printf("Mang sau khi duoc sap xep tang dan : ");
//	ouput(arr,n);
//	
	//Bubble_Sort(arr,n);
	//printf("Mang sau khi duoc sap xep tang dan : ");
	
	
	printf("Mang sau khi duoc sap xep tang dan : ");
	mergeSort(arr,0,n - 1);
	ouput(arr,n);
	
//	int min = arr[0],max = arr[0],newMax = arr[0],newMin = arr[0];
//	minMax_divide_conquer(arr,0,n - 1,&max,&min,&newMax,&newMin);
//	printf("\nMax = %d , Min = %d", max,min);
//	

	
	
	
	return 0;
}

