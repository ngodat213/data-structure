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

// Data
Node* dataNode;

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
    Node* p = dataNode->next;
    if(isEmpty(p)){
        return true;
    }else {
        while(!isEmpty(p) && p->next != dataNode){
            if(p->data.id == value){
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
    }while(!isScore(st.score)/* || !isID(st.id)*/);
}

void outputStudent(ST st){
    printf("student={id=%d, name=%s, score=%.2f}\n", st.id, st.name.c_str(), st.score);
}

// Function node struct
bool isEmpty(Node* node){
    return node == NULL;
}

void init(Node* &node){
    node = NULL;
}

Node* createNode(ST st){
    Node* node = new Node;
    if(node == NULL){
        return NULL;
    }
    node->data = st;
    return node;
}

Node* insertHead(Node* tail, ST st){
    Node* p = createNode(st);
    if(isEmpty(tail)){
        tail = p;
        p->next = p;

    }else{
        p->next = tail->next;
        tail->next = p;
    }
    return tail;
}

void showList(Node* tail){
    Node* p = tail;
    if(tail != NULL){
        do{
            p = p->next;
            outputStudent(p->data);
        }while(p != tail);
    }
}

void output_thanScore(Node* tail, float value){
    Node* p = tail;
    if(tail != NULL){
        do{
            p = p->next;
            if(p->data.score > value){
                outputStudent(p->data);
            }
        }while(p != tail);
    }
}

void find_name(Node* tail, string value){
    Node* p = tail;
    if(tail != NULL){
        do{
            p = p->next;
            if(p->data.name == value){
                outputStudent(p->data);
            }
        }while(p != tail);
    }
}

void sortStudent(Node* &tail){
    Node* i, *j;
    for(i = tail->next; i->next != tail->next; i = i->next){
        for(j = i->next; j != tail->next; j = j->next){
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
                dataNode = insertHead(dataNode, value);
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
                output_thanScore(dataNode, value);
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
    }while(1);
}
