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
// Call function
bool isScore(int score);
bool isID(int value);
void inputStudent(ST &st);
void outputStudent(ST st);
bool isEmpty(Node* node);

// Data
Node* dataNode;

// Function struct student
bool isScore(int score){
    return (score >=0 && score <= 10);
}

bool isID(int value){
    if(isEmpty(dataNode)){
        return true;
    }else {
        while(!isEmpty(dataNode)){
            if(dataNode->data.id == value){
                return false;
            }
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
    }while(!isScore(st.score) && !isID(st.id));
}

void outputStudent(ST st){
    printf("student={id=%d, name=%s, score=%.2f}", st.id, st.name.c_str(), st.score);
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
    node->next = NULL;
    return node;
}

void insertFirst(Node* &node, ST st){
    Node* p = createNode(st);
    if(isEmpty(node)){
        node = p;
    }else{
        p->next = node;
        node = p;
    }
}

void showList(Node* node){
    Node* p = node;
    while(!isEmpty(p)){
        outputStudent(p->data);
        p = p->next;
    }
}

ST output_thanScore(Node* node, float value){
    Node* p = node;
    while(!isEmpty(p)){
        if(p->data.score > value){
            outputStudent(p->data);
        }
        p = p->next;
    }
}

ST find_name(Node* node, string value){
    Node* p = node;
    while(!isEmpty(p)){
        if(p->data.name == value){
            return p->data;
        }
        p = p->next;
    }
    cout << "no info!" << endl;
}

void sortStudent(Node* &node){
    Node* i, *j;
    for(i = node; !isEmpty(node); i=i->next){
        for(j = i->next; !isEmpty(node); j=j->next){
            if(i->data.score > j->data.score){
                ST temp = i->data;
                i->data = j->data;
                j->data= temp;
            }
        }
    }
}

// Main
void menu(){
    cout << "insert student" << endl;
    cout << "output student" << endl;
    cout << "output student score than \'value\'" << endl;
    cout << "find student" << endl;
    cout << "sort student" << endl;
    cout << "[Press number of your choice]" << endl;
}
int main(){

}
