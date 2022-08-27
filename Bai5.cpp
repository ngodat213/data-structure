#include<iostream>
using namespace std;
#define MAXLIST 5

typedef struct list{
	int num;
	int nodes[MAXLIST] = {5,4,3,2,1};
}List;

void _swap(int &a, int &b){
	int tg = a;
	a = b;
	b = tg;
}

void BubbleSort(list &l){
	for(int i = 0; i < l.num-1; ++i){
		for(int j = l.num-1; j > i; --j){
			if(l.nodes[j] < l.nodes[j-1]){
				_swap(l.nodes[j], l.nodes[j-1]);
			}
		}
	}
}

int main(){
	List l;
	l.num = 5; 
	BubbleSort(l);
	for(int i = 0; i < l.num; ++i){
		cout << l.nodes[i] << " ";
	}
	return 0;
}
