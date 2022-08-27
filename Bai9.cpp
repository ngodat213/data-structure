#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100

int BinarySearchC1(int arr[], int l, int r, int x){
	while(l <= r){
		int mid = l + (r-l)/2;
		if(arr[mid] == x){
			return mid;
		}
		if(arr[mid] < x){
			l = mid+1;
			
		}
		if(arr[mid] > x){
			r = mid-1;
		}
	}
	return -1;
}

int BinarySearchC2(int arr[], int l, int r, int x){
	if(r >= l){
		int mid = l + (r-l)/2;
		if(arr[mid] == x)
			return mid;
		if(arr[mid] < x)
			return BinarySearchC2(arr, mid+1, r, x);
		return BinarySearchC2(arr, l, mid-1, x);
	}
	return -1;
}

int main(){
	int a[] = {3,2,6,10,20,1,0,-3,-20};
	sort(a, a+5);
	cout << ((BinarySearchC1(a,0,8,3) != -1) ? "Co: " << BinarySearchC2(a,0,8, 3) << endl : "Khong\n");
	cout << ((BinarySearchC2(a,0,8,3) != -1) ? "Co: " << BinarySearchC2(a,0,8, 3) << endl : "Khong\n");
	return 0;	
}
