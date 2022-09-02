#include<iostream>
#include<windows.h>

using namespace std;

// Struct Student

typedef struct Student{
    int id;
    string name;
    float score;
}ST;

void inputStudent(ST &st){
//    do{
        cout << "id: ";
        cin >> st.id;
        cout << "name: ";
        cin.ignore();
        getline(cin, st.name);
        cout << "score: ";
        cin >> st.score;
//    }while(!isScore(st.score)/* || !isID(st.id)*/);
}

void outputStudent(ST st){
    printf("student={id=%d, name=%s, score=%.2f}\n", st.id, st.name.c_str(), st.score);
}

// Struct node

struct Node{
    ST data;
    Node* prew;
    Node* next;
};

struct List{
    Node* pHead, *pTail;
};

// Call data

List listData;

void init(List &list){
    list.pHead = list.pTail = NULL;
}

bool isEmpty(Node *node){
    return node->next == NULL;
}

Node* createNode(ST data){
    Node* node = new Node;
    if(isEmpty(node)){
        return NULL;
    }
    node->data = data;
    node->next = node->prew = NULL;
    return node;
}

void insertFirst(List &list, ST st){
    Node* p = createNode(st);
    if(list.pHead == NULL){
        list.pHead = list.pTail = NULL;
    }else{
        p->next = list.pHead;
        list.pHead->prew = p;
        list.pHead = p;
    }
}
// Print data left to right
void display_l2r(List list){
    Node* p = list.pHead;
    while(p != NULL){
        outputStudent(p->data);
        p = p->next;
    }
}
// Print data right to left
void display_r2l(const List list){

}

int main(){
    init(listData);
    ST temp;
    inputStudent(temp);
    insertFirst(listData, temp);
    inputStudent(temp);
    insertFirst(listData, temp);
    inputStudent(temp);
    insertFirst(listData, temp);
    inputStudent(temp);
    insertFirst(listData, temp);
    display_l2r(listData);
    return 0;
}
