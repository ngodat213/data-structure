#include<iostream>
#include<fstream>
#include<string>
#define PATH "D:\\test\\sudoku_input.txt"
using namespace std;

void init(bool a[], int n){
	for(int i = 0; i < n; ++i){
		a[i] == 0;
	}
}

// Read sudoku 9x9
void SaveFile(char path[], int a[9][9]){
	ifstream FileIn;
	FileIn.open(path, ios_base::in);
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j){
			FileIn >> a[i][j];
		}
	}
	FileIn.close();
}

bool checkRow(int a[9][9]){
	for(int i = 0; i < 9; ++i){
		bool tmp[10] = {0};
		for(int j = 0; j < 9; ++j){
			if(a[i][j] != 0){
				if(tmp[a[i][j]]){
					return false;	
				}else{
					tmp[a[i][j]] = 1;
				}	
			}
		}
	}
	return true;
}

bool checkColumn(int a[9][9]){
	for(int i = 0; i < 9; ++i){
		bool tmp[10] = {0};
		for(int j = 0; j < 9; ++j){
			if(a[j][i] != 0){
				if(tmp[a[j][i]]){
					return false;	
				}else{
					tmp[a[j][i]] = 1;
				}	
			}
		}
	}
	return true;
}

bool Check3x3(int a[9][9]){
	for(int i = 0; i < 9; i+=3){
		for(int j = 0; j < 9; j+=3){
			bool tmp[10] = {0};
			for(int x = i; x < i+3; ++x){
				for(int y = j; y < j+3; ++y){
					if(a[x][y] != 0){
						if(tmp[a[x][y]]){
							return 0;
						}else{
							tmp[a[x][y]] = 1;
						}
					}
				}
			}
		}
	}
	return 1;
}

int main(){
	int a[9][9];
	SaveFile(PATH, a);
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	if(!checkRow(a) || !checkColumn(a) || !Check3x3(a))
		cout << 0;
	else 
		cout << 1;
	
	return 0;
}
