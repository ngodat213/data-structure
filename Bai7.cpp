// Cre HydraCoder
#include<iostream>
#define MAX_SIZE 100
using namespace std;

void _swap(int &a, int &b){
	int tg = a;
	a = b;
	b = tg;
}

int partion(int arr[], int l, int h){
	int p = arr[h];
	int i = l - 1;
	for(int j = l; j < h; ++j){
		if(arr[j] < p){
			i++;
			_swap(arr[i], arr[j]);
		}
	}
	_swap(arr[i+1], arr[h]);
	return i+1;
}

void quickSort(int arr[], int l, int h){
	if(l < h){
		int pi = partion(arr, l, h);
		quickSort(arr, l , pi-1);
		quickSort(arr, pi+1, h);
	}
}

int main(){
	int arr[5] = {5,6,3,2,4};
	quickSort(arr, 0, 4);
	for(int i = 0; i < 5; ++i){
		cout << arr[i] << " ";
	}
	return 0;
}

