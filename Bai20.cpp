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

Node* createNode(int data){
    Node* p = new Node;
    if(p == NULL){
        return NULL;
    }
    p->data = data;
    p->next = NULL;
    return p;
}

void insertFirst(Node* &node, int data){
    Node* p = createNode(data);
    if(p == NULL){
        node = p;
    }else{
        p->data = data;
        p->next = node;
        node = p;
    }
}

void insertAfter(Node* node, int data){
    Node* p = createNode(data);
    p->next = node->next;
    node->next = p;

}

void delFirst(Node* &node){
    Node* p = node;
    node = node->next;
    delete p;
}

void delAfter(Node* &node){

}

void delNode(Node* &node){
    while(node != NULL){
        delFirst(node);
    }
}

void showList(Node* node){
    Node* p = node;
    while(p != NULL){
        cout << p->data << "->";
        p = p->next;
    }
}

Node* findID(Node* node, int data){
    Node* p = node;
    while(p != NULL){
        if(p->data == data){
            return p;
        }
        p = p->next;
    }
    return NULL;
}



int main(){

    return 0;
}
