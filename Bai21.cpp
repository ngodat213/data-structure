// HydraCoder, user C++
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef struct Node* stack;

void init(stack &s){
    s = NULL;
}

bool isEmpty(stack s) {
    return (s == NULL);
}

Node* createNode(int data) {
    Node* p = new Node();
    if(p == NULL)
        return NULL;
    p->data = data;
    p->next = NULL;
    return p;
}

void push(stack &s, int data) {
    Node* ptr = createNode(data);
    if(isEmpty(s))
        s = ptr;
    else {
        ptr->next = s;
        s = ptr;
    }
}

int top(stack s) {
    if(!isEmpty(s))
        return s->data;
    else
        cout << "Stack is empty!" << endl;
}

int pop(stack &s) {
    if(!isEmpty(s)) {
        int data = s->data;
        Node* x = s;
        s = s->next;
        delete(x);
        return data;
    } else
        cout << "Stack is empty!" << endl;
}

void showStack(stack s){
    stack temp = s;
    while(temp != NULL){
        cout << pop(temp) << " ";
    }
    cout << endl;
}

stack dec_bin(int dec){
    stack s;
    while(dec != 0){
        push(s, dec%2);
        dec/=2;
    }
    return s;
}

int main() {
    stack temp;
    init(temp);
    temp = dec_bin(213);
    while(temp != NULL){
        cout << pop(temp) << " ";
    }
    return 0;
}
