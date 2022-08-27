#include<iostream>
#include<string.h>
using namespace std;

int bruteForce(char des[], char x[], int n, int m){
	int j = 0;
	int count = 0;
	for(int i = 0; i <= (n - m); ++i){
		for(j = 0; j < m && x[j] == des[i+j]; ++j); // <-- Mind (*)
			if(j >= m){
				count++;
			}
	}
	return count;	
}

int main(){
	char des[] = "ADASDAASDGKFAFA";
	char x[] = "A";
	
	int lenDes = strlen(des);
	int lenX = strlen(x);
	int res = bruteForce(des, x, lenDes, lenX);
	cout << "Xau X xuat hien: " << res << endl;
	return 0;
}
