#include<iostream>
#include<string.h>
using namespace std;

typedef struct SinhVien{
    long long id;
    string name;
    float score;
}SV;

struct Node{
    SV data;
    Node* next;
};
// STRUCT
void scanSV(SV &sv){
    cout << "ID: ";
    cin >> sv.id;
    cout << "Name: ";
    cin.ignore();
    getline(cin, sv.name);
    cout << "Score: ";
    cin >> sv.score;
}

void showSV(SV sv){
    cout << "ID: " << sv.id << endl;
    cout << "Name: " << sv.name << endl;
    cout << "Score: " << sv.score << endl;
}

// NODE

void init(Node* &pHead){
    pHead = NULL;
}

bool isEmpty(Node* node){
    return node == NULL;
}

Node* createNode(SV n){
    Node* p = new Node;
    p->data = n;
    p->next = NULL;
    return p;
}

void insertFirst(Node* &pHead, SV n){
    Node* p = createNode(n);
    if(pHead == NULL){
        pHead = p;
    }else{
        p->data = n;
        p->next = pHead;
        pHead = p;
    }
}

void insertAfter(Node* p, SV n){
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
        showSV(p->data);
        p = p->next;
    }
}

Node* findNode(Node* pHead, int id){
    Node* p = pHead;
    while(p!= NULL){
        if(p->data.id == id){
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

void deleteAfter(Node *&node){

}

int main(){
    Node* pHead;
    init(pHead);
    SV sv;
    scanSV(sv);
    insertFirst(pHead, sv);
    insertFirst(pHead, sv);
    insertFirst(pHead, sv);
    showSV(findNode(pHead, 2)->data);
    showList(pHead);
    return 0;
}
