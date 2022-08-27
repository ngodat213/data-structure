#include<bits/stdc++.h>
using namespace std;

int np[100] = {0}, n = 4;
// In cac so nhi phan (binary) n bit
void Try(int i){
	for(int j = 0; j <= 1; ++j){
		np[i] = j;
		if(i == n){
			for(int l = 1; l <= n; l++)
				cout << np[l];
			cout << endl;
		}else Try(i+1);
	}
}

int main(){
	Try(1);
	return 0;
}
