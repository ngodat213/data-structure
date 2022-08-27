#include<iostream>
using namespace std;

void Print(int n){
	if(n < 0)
		return;
	Print(n-1);
	cout << n << " ";
}

int main(){
	cout << "De quy in 0 -> n: ";
	Print(5);
	return 0;
}
