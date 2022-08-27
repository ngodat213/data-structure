#include<iostream>
using namespace std;

// Fibonacci su dung quy hoach dong
long long tmp[200];
void init(){
	for(int i = 0; i < 200; ++i){
		tmp[i] = -1;
	}
}

long long FiboQHD(int n){
	if(tmp[n] == -1)
	{
		if(n <= 1)
			tmp[n] = n;
		else
			tmp[n] = FiboQHD(n-1) + FiboQHD(n-2);
	}
	return tmp[n];
}

int main(){
	init();
	cout << "Fibo QHD 40: " << FiboQHD(100);
	return 0;	
}
