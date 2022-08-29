#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void init(Node* &pHead){
    pHead = NULL;
}

bool isEmpty(Node* node){
    return node == NULL;
}

Node* createNode(int n){
    Node* p = new Node;
    p->data = n;
    p->next = NULL;
    return p;
}

void insertFirst(Node* &pHead, int n){
    Node* p = createNode(n);
    if(pHead == NULL){
        pHead = p;
    }else{
        p->data = n;
        p->next = pHead;
        pHead = p;
    }
}

void insertAfter(Node* p, int n){
	Node* tmp = createNode(n);
	tmp->next = p->next;
	p->next = tmp;
}

void deleteFirst(Node* &pHead){
    Node* p = pHead;
    pHead = pHead->next;
    delete p;
}

void showList(Node* pHead){
    Node* p = pHead;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
}

Node* findNode(Node* pHead, int n){
    Node* p = pHead;
    while(p!= NULL){
        if(p->data == n){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void deleteNode(Node* &pHead){
	while(pHead != NULL){
		deleteFirst(pHead);
	}
}

int main(){
    Node* pHead;
    init(pHead);
    insertFirst(pHead, 1);
    insertFirst(pHead, 2);
    insertFirst(pHead, 3);
    showList(pHead);
    deleteFirst(pHead);
    showList(pHead);
    return 0;
}
