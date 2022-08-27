#include <iostream>

using namespace std;

/*
    Cac cach duyet cay
    1.Node Left Right(*)
    2.Node Right Left
    3.Left Node Rigth
    4.Right Node Left
    5.Left Rigth Node
    6.Right Lift Node
*/

typedef struct Node{
    int data;
    Node* pLeft;
    Node* pRight;
}NODE;

typedef NODE* Tree;

void init(Tree &tree){
    tree = NULL;
}

void pushTree(Tree &tree, int x){
    if(tree == NULL){
        NODE *p = new NODE;
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        tree = p;
    }else{
        if(tree->data > x){
            pushTree(tree->pLeft, x);
        }else if(tree->data < x){
            pushTree(tree->pRight, x);
        }
    }
}

void printTree(Tree tree){
    if(tree != NULL){
        cout << tree->data << " ";
        printTree(tree->pLeft);
        printTree(tree->pRight);
        cout << endl;
    }
}

int main()
{
    Tree tree;
    init(tree);
    int n;
    cin >> n;
    for(int  i = 0; i < n; ++i){
        int a;
        cin >> a;
        pushTree(tree, a);
    }
    printTree(tree);
    return 0;
}