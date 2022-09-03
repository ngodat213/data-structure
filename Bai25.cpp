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
//    if(isEmpty(node)){
//        return NULL;
//    }
    node->data = data;
    node->next = node->prew = NULL;
    return node;
}

void insertFirst(List &list, ST st){
    Node* p = createNode(st);
    if(list.pHead == NULL){
        list.pHead = list.pTail = p;
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

void output_thanScore(const List list, float value){
    Node* p = list.pHead;
    while(p != NULL){
        if(p->data.score > value){
            outputStudent(p->data);
        }
        p = p->next;
    }
}

Node* find_name(List list, string value){
    Node *p = list.pHead;
    while(p!= NULL){
        if(p->data.name == value){
            outputStudent(p->data);
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void sortStudent(List &list){
    Node *i, *j;
    for(i = list.pHead; i != NULL; i = i->next){
        for(j = i->next; j != NULL; j = j->next){
            if(i->data.score > j->data.score){
                ST st = i->data;
                i->data = j->data;
                j->data = st;
            }
        }
    }
}

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
    init(listData);
    do{
        menu();
        int choise;
        cin >> choise;
        switch(choise){
            case 1:{
                ST value;
                inputStudent(value);
                insertFirst(listData, value);
                break;
            }
            case 2:{
                display_l2r(listData);
                break;
            }
            case 3:{
                float value;
                cout << "score target: ";
                cin >> value;
                output_thanScore(listData, value);
                break;
            }
            case 4:{
                string value;
                cout << "name target: ";
                cin.ignore();
                getline(cin, value);
                Node* temp = find_name(listData, value);
                outputStudent(temp->data);
                break;
            }
            case 5:{
                sortStudent(listData);
                break;
            }
            case 6:
                return true;
        }
        system("pause");
        system("cls");
    }while(1);
    return 0;
}
