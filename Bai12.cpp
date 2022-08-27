#include<iostream>
using namespace std;

int IsSorted(int a[], int n){
	if(a[n-2] > a[n-1])
		return 0;
	if(n == 1)
		return 1;
	return IsSorted(a, n-1);
}

int main(){
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	cout << "Is sorted: " << IsSorted(a,10);
	return 0;
}
