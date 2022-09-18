#include<bits/stdc++.h>
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
// NLR
void preOder(Tree* tree){
    if(tree == NULL){
        return;
    }
    cout << tree->data << " ";
    preOder(tree->pLeft);
    preOder(tree->pRight);
}
// LNR
void inOder(Tree* tree){
    if(tree == NULL){
        return;
    }
    preOder(tree->pLeft);
    cout << tree->data << " ";
    preOder(tree->pRight);
}
// LRN
void postOder(Tree* tree){
    if(tree == NULL){
        return;
    }
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

void arrToTree(Tree* &tree, int arr[], int len){
    for(int i = 0; i < len; ++i){
        insertTree(tree, arr[i]);
    }
}

void levelOder(Tree* tree){
    if(tree == NULL){
        return;
    }
//    if(level == 1)
}

void inputArr(int a[], int n){
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

int lengthTree(Tree* proot){
    if(proot == NULL){
        return 0;
    }
    int lengthLeft = lengthTree(proot->pLeft);
    int lengthRight = lengthTree(proot->pRight);
    return max(lengthLeft, lengthRight);
}


Tree* findTree(Tree* proot, int dataTarget){
    if(proot == NULL){
        return NULL;
    }
    if(proot->data == dataTarget){
        return proot;
    }
    if(dataTarget < proot->data){
        findTree(proot->pLeft, dataTarget);
    }else{
        findTree(proot->pRight, dataTarget);
    }
}

int countLeaft(Tree* proot){
    int static count = 0;
    if(proot->pLeft == NULL || proot->pRight){
        count++;
    }
    countLeaft(proot->pLeft);
    countLeaft(proot->pRight);
    return count;
}

void menu(){
    cout << "1. Insert node" << endl;
    cout << "2. Insert node with array" << endl;
    cout << "3. NLR" << endl;
    cout << "4. LNR" << endl;
    cout << "5. LRN" << endl;
    cout << "6. Level" << endl;
    cout << "7. Search node" << endl;
    cout << "8. Length node" << endl;
    cout << "9. Count node" << endl;
    cout << "10. Count leaf" << endl;
}

int main(){
    Tree* proot;
    init(proot);
    do{
        menu();
        int choice;
        cout << choice;
        switch(choice) {
            case 1:{
                int data;
                cin >> data;
                insertTree(proot, data);
                break;
            }
            case 2:{
                cout << "length arr: ";
                int n;
                cin >> n;
                int a[n];
                inputArr(a, n);
                arrToTree(proot, a, n);
                break;
            }
            case 3:{
                cout << "NLR: ";
                preOder(proot);
                break;
            }
            case 4:{
                cout << "LRN: ";
                inOder(proot);
                break;
            }
            case 5:{
                cout << "LRN: ";
                postOder(proot);
                break;
            }
            case 6:{
                cout << "Level: ";
                levelOder(proot);
                break;
            }
            case 7:{
                int dataTarget;
                cin >> dataTarget;
                Tree* res = findTree(proot, dataTarget);
                if(res == NULL){
                    cout << "no info!" << endl;
                }else{
                    cout << res->data << endl;
                }
                break;
            }
            case 8:{

            }
        }
    }while(1);
    return 0;
}
