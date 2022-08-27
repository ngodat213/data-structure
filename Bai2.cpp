//Cre: HydraCoder, user C++
#include<iostream>
using namespace std;

int current_size = -1;
const int MAX_SIZE = 100;
int stack[MAX_SIZE];

bool isEmpty(){
    return current_size == -1;
}

bool isFull(){
    return current_size == MAX_SIZE;
}

int push(int data){
    if(!isFull()){
        current_size++;
        stack[current_size] = data;
    }else{
        cout << "Stack full!" << endl;
    }
}

int top(int data){
    if(!isEmpty()){
        int data = stack[current_size];
        return data;
    }else{
        cout << "Stack is empty!" << endl;
    }
}

int pop(){
    if(!isEmpty()){
        int data = stack[current_size];
        current_size--;
        return data;
    }else{
        cout << "Stack is empty!" << endl;
    }
}

//int main(){
//    push(26);
//    push(10);
//    push(2003);
//    while(!isEmpty()){
//        cout << pop() << endl;
//    }
//}
