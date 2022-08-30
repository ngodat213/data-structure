#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

typedef struct QUEUE{
    Node* pHead;
    Node* pTail;
}Queue;

bool isEmptyQueue(Queue q){
    if(q.pHead == NULL){
        return 1;
    }
    return 0;
}

void init(Node* &node){
    node = NULL;
}

void initQueue(Queue &q){
    q.pHead = NULL;
    q.pTail = NULL;
}

Node* createNode(int n){
    Node* node = new Node;
    if(node == NULL)
        return NULL;
    node->data = n;
    node->next = NULL;
    return node;
}

void insertQueue(Queue &q, int n){
    Node* p = createNode(n);
    if(isEmptyQueue(q)){
        q.pHead = q.pTail = p;
    }else{
        q.pTail->next = p;
        q.pTail = p;

    }
}

void showQueue(Queue q){
    Queue p = q;
    while(!isEmptyQueue(p)){
        cout << p.pHead->data;
        p.pHead = p.pHead->next;
    }
}

int removeQueue(Queue &q){
    if(!isEmptyQueue(q)){
        int value = q.pHead->data;
        q.pHead = q.pHead->next;
        return value;
    }
}

int main(){
    Queue q;
    initQueue(q);
    insertQueue(q, 1);
    insertQueue(q, 2);
    insertQueue(q, 3);
    insertQueue(q, 4);
    while(!isEmptyQueue(q)){
        cout << removeQueue(q) <<  " ";
    }
    return 0;
}
