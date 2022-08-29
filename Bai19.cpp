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

void deleteAfter(Node *node){

}

void del_id(Node* &pHead, int value){
    if(!isEmpty(pHead)){
        Node* tmp = pHead;
        if(pHead->data.id == value){
            pHead = pHead->next;
            delete tmp;
        }else{
            Node* p = NULL;
            while(tmp!=NULL && tmp->data.id!=value){
                p = tmp;
                tmp = tmp->next;
            }
            if(tmp != NULL){
                p->next = tmp->next;
                delete tmp;
            }
        }
    }
}

void sortNode(Node* &node){
    Node* i, *j;
    for(i = node; i != NULL; i = i->next){
        for(j = i->next; j != NULL; j = j->next){
            if(i->data.id > j->data.id){
                int tmp = i->data.id;
                i->data.id = j->data.id;
                j->data.id = tmp;
            }
        }
    }
}

// Function menu
void menu1(){
    cout << "1. insert first student" << endl;
    cout << "2. insert after student" << endl;
    cout << "3. delete by id student" << endl;
    cout << "4. delete first student" << endl;
    cout << "5. delete after student" << endl;
    cout << "6. show list student" << endl;
    cout << "7. find node student" << endl;
    cout << "8. delete all node" << endl;
    cout << "9. sort node student" << endl;
    cout << "10. exit" << endl;
    cout << "[Press the number of your choice]" << endl;
}

void menu(){
    cout << "1. insert first student" << endl;
    cout << "2. insert after student" << endl;
    cout << "3. delete by id student" << endl;
    cout << "4. show list student" << endl;
    cout << "5. find node student" << endl;
    cout << "6. delete all node" << endl;
    cout << "7. sort node student" << endl;
    cout << "8. exit" << endl;
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
        case 3:{
            int value;
            cout << "enter id to delete student: ";
            cin >> value;
            del_id(pHead, value);
        }
            break;
        case 4:
            showList(pHead);
            break;
        case 5:{
            int value;
            cout << "enter id to find student" << endl;
            cin >> value;
            if(findNode(pHead, value) != NULL){
                outputStudent(findNode(pHead, value)->data);
            }else{
                cout << "no info!" << endl;
            }
        }
            break;
        case 6:{
            deleteNode(pHead);
            cout << "delete successful!" << endl;
        }
        case 7:{
            sortNode(pHead);
            showList(pHead);
        }
            break;
        }
    }
    return 0;
}

