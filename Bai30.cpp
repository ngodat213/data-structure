#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
    void init(Node* &node){
        node = NULL;
    }

    Node* createNode(int data){
        Node* p;
        if(p == NULL){
            return NULL;
        }
        p->data = data;
        p->next = NULL;
        return p;
    }

    Node* insertFirst(Node* node, int data){
        Node* p = createNode(data);
        if(node == NULL){
            return p;
        }
        p->next = node;
        return p;
    }

    Node* insertAfter(Node* node, int data){
        Node* p = createNode(data);
        if(node == NULL){
            return p;
        }
        p->next = node->next;
        node->next = p;
        return node;
    }

    Node* deleteFirst(Node* node){
        Node* p;
        if(node == NULL){
            cout << "node is empty!" << endl;
        }else{
            p = node;
            node = node->next;
            delete p;
        }
        return node;
    }

    Node* deleteAfter(Node* node){
        Node* p;
        if(node == NULL || node->next == NULL){
            cout << "cannot delete!" << endl;
        }else{
            p = node->next;
            node->next = p->next;
            delete p;
        }
        return node;
    }

    Node* clearList(Node* node){
        do{
            deleteFirst(node);
        }while(node != NULL)
        return node;
    }

    void toString(Node* node){
        Node* p = node;
        while(p != NULL){
            cout << p->data << " ";
            p=p->next;
        }
        cout << endl;
    }

    Node* searchList(Node* node, int target){
        Node* p = node;
        while(p != NULL || p->data != target){
            if(p->data == target){
                return p;
            }
            p = p->next;
        }
        cout << "no info!" << endl;
    }

    Node* sortList(Node* node, bool op){
        Node* p,*q;
        if(op){
            for(p = node; p->next != NULL; p=p->next){
                for(q = p->next; q!= NULL; q=q->next){
                    if(p.data > q.data){
                        int temp = p->data;
                        p->data = q->data;
                        q->data = tmp;
                    }
                }
            }
        }else{
            for(p = node; p->next != NULL; p=p->next){
                for(q = p->next; q!= NULL; q=q->next){
                    if(p.data < q.data){
                        int temp = p->data;
                        p->data = q->data;
                        q->data = tmp;
                    }
                }
            }
        }
        return node;
    }

    Node* posNode(Node* phead, int target){
        Node* p = pHead;
        int pos = 0;
        while(p != NULL && cmt < target){
            p=p->next;
            pos++;
        }
        return p;
    }

    Node* position(Node* phead, Node* q){
        int pos = 0;
        Node* p = pHead;
        while(p != NULL && p != q){
            p=p->next;
            pos++;
        }
        if(p == NULL){
            return -1;
        }
        return pos;
    }

    Node* preNode(Node* pHead, Node* q){
        Node* p;
        if(q == pHead){
            return NULL;
        }
        p= pHead;
        while(p!=NULL && p->next != q){
            p=p->next;
        }
        return p;
    }

    void place(Node* &pHead, int x){
        Node* p, * q;
        q = NULL;
        for(p=pHead; p!= NULL && x > p->data; p=p->next){
            `q=p;
        }
        if(q == NULL){
            insertFirst(pHead, x);
        }else{
            insertAfter(pHead, x);
        }
    }

    // delete
};

class DoubLinkedList{

};

class Tree{

};


int main(){

    return 0;
}
