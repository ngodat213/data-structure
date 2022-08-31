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

void insertFirst(Node* &node, ST st);

int main(){

}
