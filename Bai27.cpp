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

Tree* search_tree(Tree* tree, int target){
    Tree* p = tree;
    if(p->data == target){
        return p;
    }
    if(isEmpty(tree)){
        return NULL;
    }
}

int main(){

    return 0;
}
