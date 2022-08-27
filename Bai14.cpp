#include<iostream>
using namespace std;

void swap(int n, char a, char b){
	cout << a << " -> " << b << endl;
}

void HN(int n, char a, char b, char c){
	if(n == 1) swap(1, a, c);
	else{
		HN(n-1, a, c, b);
		swap(n, a, c);
		HN(n-1, b, a, c);
	}
		
}

int main(){
	int n;
	char a = 'A', b = 'B', c = 'C';
	cin >> n;
	HN(n, a, b, c);
	return 0;
}
