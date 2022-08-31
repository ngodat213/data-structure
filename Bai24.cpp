#include<iostream>
#include<windows.h>
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

struct List{
    Node *pHead;
    Node *pTail;
};

// Data
List listData;

// Call function
bool isScore(int score);
bool isID(int value);
void inputStudent(ST &st);
void outputStudent(ST st);
bool isEmpty(Node* node);

// Function struct student
bool isScore(int score){
    return (score >=0 && score <= 10);
}

bool isID(int value){
    List l = listData;
    if(isEmpty(l)){
        return true;
    }else {
        while(!isEmpty(l)){
            if(l->data.id == value){
                return false;
            }
            p = p->next;
        }
    }
    return true;
}

void inputStudent(ST &st){
    do{
        cout << "id: ";
        cin >> st.id;
        cout << "name: ";
        cin.ignore();
        getline(cin, st.name);
        cout << "score: ";
        cin >> st.score;
    }while(!isScore(st.score) || !isID(st.id));
}

void outputStudent(ST st){
    printf("student={id=%d, name=%s, score=%.2f}\n", st.id, st.name.c_str(), st.score);
}

// Function node struct
bool isEmpty(List l){
    return l.pHead == NULL;
}

void init(List &l){
    l.pHead = l.pHead = NULL;
}

Node* createNode(ST st){
    Node* node = new Node;
    if(node == NULL){
        return NULL;
    }
    node->data = st;
    node->next = NULL;
    return node;
}

void insertHead(List &l, ST st){
    Node* p = createNode(st);
    if(isEmpty(l)){
        l.pHead = l.pTail = p;
    }else{
        p->next = l.pHead;
        l.pHead = p;
    }
}

void insertTaiL(List &l, ST st){
    Node*p = createNode(st);
    if(isEmpty(l)){
        insertHead(l, st);
    }else{
        l.pTail->next = p;
        l.pTail = p;
    }
}

void showList(Node* node){
    Node* p = node;
    while(!isEmpty(p)){
        outputStudent(p->data);
        p = p->next;
    }
}

ST output_thanScore(float value){
    Node* p = dataNode;
    while(!isEmpty(p)){
        if(p->data.score > value){
            outputStudent(p->data);
        }
        p = p->next;
    }
}

void find_name(Node* node, string value){
    Node* p = node;
    int n = 0;
    while(!isEmpty(p)){
        if(p->data.name == value){
            outputStudent(p->data);
            n++;
        }
        p = p->next;
    }
    if(n == 0){
        cout << "no info" << endl;
    }
}

void sortStudent(Node* &node){
    Node* i, *j;
    for(i = node; i != NULL; i = i->next){
        for(j = i->next; j != NULL; j = j->next){
            if(i->data.score > j->data.score){
                ST temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Main
void menu(){
    cout << "1. insert student" << endl;
    cout << "2. output student" << endl;
    cout << "3. output student score than \'value\'" << endl;
    cout << "4. find student" << endl;
    cout << "5. sort student" << endl;
    cout << "6. exit" << endl;
    cout << "[Press number of your choice]" << endl;
}
int main(){
    do{
        menu();
        int choise;
        cin >> choise;
        switch(choise){
            case 1:{
                ST value;
                inputStudent(value);
                insertHead(listData, value);
                break;
            }
            case 2:{
                showList(dataNode);
                break;
            }
            case 3:{
                float value;
                cout << "score target: ";
                cin >> value;
                output_thanScore(value);
                break;
            }
            case 4:{
                string value;
                cout << "name target: ";
                cin.ignore();
                getline(cin, value);
                find_name(dataNode, value);
                break;
            }
            case 5:{
                sortStudent(dataNode);
                break;
            }
            case 6:
                return true;
        }
        system("pause");
        system("cls");
    }while(true);
}
