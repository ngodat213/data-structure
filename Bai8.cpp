// Cre HydraCoder
#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int h){
	int i, j, k = l;
	int n1 = m-l+1;
	int n2 = h-m;
	int *L = new int[n1];
	int *R = new int[n2];
	for(int i = 0; i < n1; ++i){
		L[i] = arr[l+i];
	}
	for(int i = 0; i < n2; ++i){
		R[i] = arr[m+i+1];
	}
	
	i = 0; j = 0;
	while(i < n1 && j < n2){
		arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
	}
	
	while(i < n1){
		arr[k++] = L[i++];
	}
	while(j < n2){
		arr[k++] = R[j++];
	}
}

void mergeSort(int arr[], int l, int h){
	if(l < h){
		int m = l + (h-l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, h);
		merge(arr, l, m, h);
	}
}

int main(){
	int arr[] = {-10,4,2,5,5,2,7,12,26, 2003};
	mergeSort(arr, 0, 9);
	for(int i = 0; i < 10; ++i){
		cout << arr[i] << " ";
	}
	return 0;
}

