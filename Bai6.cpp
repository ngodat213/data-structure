// Cre HydraCoder
#include<iostream>
#define MAX_SIZE 100
using namespace std;

typedef struct list{
	int num;
	int nodes[MAX_SIZE] = {5,4,6,3,4};
}List;

void _swap(int &a, int &b){
	int tg = a;
	a = b;
	b = tg;
}

void selectionSort(List &l){
	for(int i = 0; i < l.num-1; ++i){
		int min_index = i;
		for(int j = i+1; j < l.num; ++j){
			if(l.nodes[min_index] > l.nodes[j])
				min_index = j;
		}
		_swap(l.nodes[i], l.nodes[min_index]);
	}
}

int main(){
	List l;
	l.num = 5;
	selectionSort(l);
	for(int i = 0; i < l.num; ++i){
		cout << l.nodes[i] << " ";
	}
	return 0;	
}
