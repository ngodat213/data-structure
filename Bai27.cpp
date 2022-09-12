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
    Tree* t = new Node;
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

void insertTree(Tree* &tree, int data){
    Tree* p = createTree(data);
    if(tree == NULL){
        tree = p;
    }else{
        if(data > tree->data){
            insertTree(tree->pRight, data);
        }else{
            insertTree(tree->pLeft, data);
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

void clearTree(Tree* tree){
    if(tree != NULL){
        clearTree(tree->pLeft);
        clearTree(tree->pRight);
        delete tree;
    }
}

int deleteLeft(Tree* p){
    Tree* q;
    int x;
    if(p == NULL){
        cout << "tree is empty\n";

    }else{
        q = p->pLeft;
        x = q->data;
        if(q == NULL){
            cout << "tree left is null\n";
        }else{
            if(q->pLeft != NULL || q->pRight != NULL){
                cout << "not is last node\n";
            }else{
                q->pLeft = NULL;
                delete q;
            }
        }
    }
    return x;
}

int deleteRight(Tree* p){
    Tree* q;
    int x;
    if(p == NULL){
        cout << "tree is empty\n";
    }else{
        q = p->pRight;
        x = q->data;
        if(q == NULL){
            cout << "tree right is null\n";
        }else{
            if(q->pLeft != NULL || q->pRight != NULL){
                cout << "not is last tree\n";
            }else{
                p->pRight = NULL;
                delete q;
            }
        }
    }
    return x;
}

bool removeTree(Tree* tree, int x){
    if(tree == NULL){
        return 0;
    }
    if(tree->data > x){
        return removeTree(tree->pLeft, x);
    }
    if(tree->data < x){
        return removeTree(tree->pRight, x);
    }
    // tree->data = x
    Node *t, *f, *rp;
    t = tree;
    // TH1, 1 node
    if(tree->pLeft == NULL){
        tree = tree->pRight;
    }else if(tree->pRight == NULL){
        tree = tree->pRight;
    }else{
        f = t;
        rp = t->pRight; // start from pRight
        while(rp ->pLeft != NULL){
            f = rp;
            rp = rp->pLeft;
        }
        t->data = rp->data;
        if(f == t){
            f->pRight = rp->pRight;
        }else{
            f->pLeft = rp->pRight;
        }
        t = rp;
    }
    delete t;
    return 1;
}

int main(){

    return 0;
}
