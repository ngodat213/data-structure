#include<iostream>
#include<math.h>
using namespace std;
/*
	Nhung vi tri con hau(queen) duoc di trong ma tran 8x8
*/
int a[8];
bool check(int x2, int y2){
	for(int i = 1; i < x2; ++i){
		/* 
			DK a[i] == y2 -> Check xem a[i] co trung voi vi tri queen da dat truoc do hay chua
			DK abs(i - x2) == abs(a[i] - y2) -> Check xem co nam tren duong cheo hay khong
		*/
		if(a[i] == y2 || abs(i - x2) == abs(a[i] - y2)){ // <- Algorithm
			return 0;
		}
	}
	return 1;
}

void Print(int n){
	for(int i = 1; i < n; ++i){
		cout << a[i] << " ";
	}
	cout << endl;
}

void NQueen(int i, int n){
	for(int j = 1; j <= n; ++j){
		if(check(i, j)){
			a[i] = j;
			if(i == n) Print(n);
			NQueen(i+1, n);
		}
	}
}

int main(){
	int n = 8;
	NQueen(1, n);
	return 0;
}
