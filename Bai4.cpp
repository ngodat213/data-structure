// HydraCoder, use C++
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

typedef struct Node* queue;

bool isEmpty(queue q){
    return q == NULL;
}

Node* createNode(int data){
    Node *P = new Node();
    if(P == NULL)
        return NULL;
    P->data = data;
    P->next = NULL;
}

int enQueue(queue &q, int data){
    Node* p = createNode(data);
    if(q == NULL){
        q = p;
    }
    else{
        Node *ptr = q;
        while(ptr != NULL && ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = p;
    }
}

int peek(queue q){
    if(!isEmpty(q)){
        return q->data;
    }else{
        return 0;
    }
}

int deQueue(queue &q){
    if(!isEmpty(q)){
        int data = q ->data;
        Node* p = q;
        q = q->next;
        delete(p);
        return data;
    }else{
        return 0;
    }
}

int main(){
    queue q;
    enQueue(q, 26);
    enQueue(q, 10);
    enQueue(q, 2003);
    while(!isEmpty(q)){
        int data = peek(q);
        deQueue(q);
        cout << data << " ";
    }
    return 0;
}
