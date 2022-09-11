#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* pLeft;
    Node* pRight;
}Tree;

void init(Tree* &tree){
    tree->pLeft = NULL;
    tree->pRight = NULL;
}

bool isEmpty(Tree* tree){
    return (tree->pLeft == NULL && tree->pRight == NULL);
}

Tree* createTree(int data){
    Tree t = new Tree;
    if(t == NULL){
        return NULL;
    }
    t->data = data;
    t->pLeft = NULL;
    t->pRight = NULL;
    return t;
}
// NRL
void preOder(Tree* tree){
    cout << tree->data << " ";
    preOder(tree->pLeft);
    preOder(tree->pRight);
}
// LNR
void inOder(Tree* tree){
    preOder(tree->pLeft);
    cout << tree->data << " ";
    preOder(tree->pRight);
}
// LRN
void postOder(Tree* tree){
    preOder(tree->pLeft);
    preOder(tree->pRight);
    cout << tree->data << " ";
}

void insertFirst(Tree* &tree, int data){
    Tree* p = createTree(data);
    if(tree == NULL){
        tree = p;
    }else{
        if(data > tree.data){
            insertFirst(tree->pRight, data);
        }else{
            insertFirst(tree->pLeft, data)
        }
    }
}

Tree* tree_search(Tree* tree, int key){
    Tree* p = tree;
    if(p->data == key){
        return p;
    }
    if(p->data > key){
        tree_search(p->pLeft, key);
    }else{
        tree_search(p->pRight, key);
    }
    return NULL;
}

int main(){

    return 0;
}
