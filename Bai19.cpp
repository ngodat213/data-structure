#include<iostream>
using namespace std;

typedef struct Student{
    int id;
    string name;
    float score;
}ST;

struct Node{
    ST data;
    Node* next;
};
// Function struct SV
void inputStudent(ST &st){
    cout << "id: ";
    cin >> st.id;
    cout << "name: ";
    cin.ignore();
    getline(cin, st.name);
    cout << "score: ";
    cin >> st.score;
}

void outputStudent(ST st){
    printf("student{id=%d, name=\'%s\', score=%.2f}\n", st.id, st.name.c_str(), st.score);
}

// Function node

void init(Node* &pHead){
    pHead = NULL;
}

bool isEmpty(Node* node){
    return node == NULL;
}

Node* createNode(ST n){
    Node* p = new Node;
    p->data = n;
    p->next = NULL;
    return p;
}

void insertFirst(Node* &pHead, ST n){
    Node* p = createNode(n);
    if(pHead == NULL){
        pHead = p;
    }else{
        p->data = n;
        p->next = pHead;
        pHead = p;
    }
}

void insertAfter(Node* p, ST n){
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
        outputStudent(p->data);
        p = p->next;
    }
}

Node* findNode(Node* pHead, int n){
    Node* p = pHead;
    while(p!= NULL){
        if(p->data.id == n){
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

void deleteByID(Node* &pHead){

}

void deleteAfter(Node *node){
    Node* p;
}
// Function menu
void menu(){
    cout << "1. insert first student" << endl;
    cout << "2. insert after student" << endl;
    cout << "3. delete by id student" << endl;
    cout << "4. show list student" << endl;
    cout << "5. find node student" << endl;
    cout << "6. delete all node" << endl;
    cout << "7. exit" << endl;
    cout << "[Press the number of your choice]" << endl;
}

int main(){
    Node* pHead;
    init(pHead);
    while(true){
        menu();
        int choice;
        cin >> choice;
        switch(choice){
        case 1: {
            ST st;
            inputStudent(st);
            insertFirst(pHead, st);
        }
            break;
        case 2: {
            ST st;
            inputStudent(st);
            insertAfter(pHead, st);
        }
            break;
        case 3:
            break;
        case 4:
            showList(pHead);
            break;
        case 7:
            return false;
        }
    }
    return 0;
}

