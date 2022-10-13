#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

struct Tree{
    int data;
    Tree* pLeft;
    Tree* pRight;
    int height;
};

void toString(Node* node){
        Node* p = node;
        while(p != NULL){
            cout << p->data << " ";
            p=p->next;
        }
        cout << endl;
    }

typedef struct Node* stackN;
typedef struct Node* queueN;

class LinkedList{

public:
    void init(Node* &node){
        node = NULL;
    }

    Node* createNode(int data){
        Node* p = new Node;
        if(p == NULL){
            return NULL;
        }
        p->data = data;
        p->next = NULL;
        return p;
    }

    Node* insertFirst(Node* node, int data){
        Node* p = createNode(data);
        if(node == NULL){
            return p;
        }
        p->next = node;
        return p;
    }

    Node* insertAfter(Node* node, int data){
        Node* p = createNode(data);
        if(node == NULL){
            return p;
        }
        p->next = node->next;
        node->next = p;
        return node;
    }

    Node* insertFirst_Arr(Node* node, int n){
        int a[n];
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            node = insertFirst(node, a[i]);
        }
        return node;
    }

    Node* insertAfter_Arr(Node* node, int n){
        int a[n];
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            node = insertAfter(node, a[i]);
        }
        return node;
    }

    Node* deleteFirst(Node* node){
        Node* p;
        if(node == NULL){
            cout << "node is empty!" << endl;
        }else{
            p = node;
            node = node->next;
            delete p;
        }
        return node;
    }

    Node* deleteAfter(Node* node){
        Node* p;
        if(node == NULL || node->next == NULL){
            cout << "cannot delete!" << endl;
        }else{
            p = node->next;
            node->next = p->next;
            delete p;
        }
        return node;
    }

    Node* clearList(Node* node){
        do{
            deleteFirst(node);
        }while(node != NULL);
        return node;
    }

    void toString(Node* node){
        Node* p = node;
        while(p != NULL){
            cout << p->data << " ";
            p=p->next;
        }
        cout << endl;
    }

    Node* searchList(Node* node, int target){
        Node* p = node;
        while(p != NULL){
            if(p->data == target){
                return p;
            }
            p = p->next;
        }
        cout << "no info!" << endl;
        return NULL;
    }

    Node* sortList(Node* node, bool op){
        Node* p,*q;
        if(op){
            for(p = node; p->next != NULL; p=p->next){
                for(q = p->next; q!= NULL; q=q->next){
                    if(p->data > q->data){
                        int temp = p->data;
                        p->data = q->data;
                        q->data = temp;
                    }
                }
            }
        }else{
            for(p = node; p->next != NULL; p=p->next){
                for(q = p->next; q!= NULL; q=q->next){
                    if(p->data < q->data){
                        int temp = p->data;
                        p->data = q->data;
                        q->data = temp;
                    }
                }
            }
        }
        return node;
    }

    Node* posNode(Node* pHead, int target){
        Node* p = pHead;
        int pos = 0;
        while(p != NULL && pos < target){
            p=p->next;
            pos++;
        }
        return p;
    }

    int position(Node* pHead, int target){
        int pos = 0;
        Node* p = pHead;
        while(p != NULL){
            if(p->data == target){
                return pos;
            }
            p=p->next;
            pos++;
        }
        if(p == NULL){
            return -1;
        }
    }

    Node* preNode(Node* pHead, Node* q){
        Node* p;
        if(q == pHead){
            return NULL;
        }
        p= pHead;
        while(p!=NULL && p->next != q){
            p=p->next;
        }
        return p;
    }

    void place(Node* &pHead, int x){
        Node* p, * q;
        q = NULL;
        for(p=pHead; p!= NULL && x > p->data; p=p->next){
            q=p;
        }
        if(q == NULL){
            insertFirst(pHead, x);
        }else{
            insertAfter(pHead, x);
        }
    }

    void deleteNode(Node* pHead, int targetdata) {
        if (pHead != NULL) {
            Node * currNode = pHead;
            if (pHead->data == targetdata){
                pHead = pHead->next;
                delete currNode;
            }else {
                Node * prevNode = NULL;
                while (currNode != NULL && currNode->data != targetdata) {
                    prevNode = currNode;
                    currNode = currNode->next;
                }
                if (currNode != NULL) {
                    prevNode->next = currNode->next;
                    delete currNode;
                }
            }
        }
    }
};

class DoubLinkedList{

};

class TreeBST{
public:
    Node* createNode(int data){
        Node* p;
        if(p == NULL){
            return NULL;
        }
        p->data = data;
        p->next = NULL;
        return p;
    }

    void init(Tree* &tree){
        tree = NULL;
    }

    Tree* createTree(int data){
        Tree* proot;
        proot->data = data;
        proot->pLeft = proot->pRight = NULL;
        return proot;
    }

    void addNode(Tree* &proot, int data){
        Tree* p = createTree(data);
        if(proot != NULL){
            if(proot->data == data){
                return;
            }
            if(data < proot->data){
                addNode(proot->pLeft, data);
            }else if(data > proot->data){
                addNode(proot->pRight, data);
            }
        }else{
            proot = p;
        }
    }
// -- PRINT --
    void NLR(Tree* proot){
        if(proot){
            cout << proot->data << " ";
            NLR(proot->pLeft);
            NLR(proot->pRight);
        }else{
            cout << endl;
        }
    }

    void LNR(Tree* proot){
        if(proot){
            LNR(proot->pLeft);
            cout << proot->data << " ";
            LNR(proot->pRight);
        }else{
            cout << endl;
        }
    }

    void LRN(Tree* proot){
        if(proot){
            LRN(proot->pLeft);
            LRN(proot->pRight);
            cout << proot->data << " ";
        }else{
            cout << endl;
        }
    }

    Tree* searchTree(Tree* proot, int val){
        if(proot){
            if(proot->data == val){
                return proot;
            }else if(val < proot->data){
                searchTree(proot->pLeft, val);
            }else if(val > proot->data){
                searchTree(proot->pRight, val);
            }
        }else{
            return NULL;
        }
    }

    int countTree(Tree* proot){
        if(proot){
            return 1 + countTree(proot->pLeft) + countTree(proot->pRight);
        }else{
            return 0;
        }
    }

    int countLeaf(Tree* proot){
        if(proot){
            if(proot->pLeft == NULL && proot->pRight == NULL){
                return 1;
            }else{
                return countLeaf(proot->pLeft) + countLeaf(proot->pRight);
            }
        }else{
            return 0;
        }
    }

    int sumTree(Tree* proot){
        if(proot){
            return proot->data + sumTree(proot->pLeft) + sumTree(proot->pRight);
        }else{
            return 0;
        }
    }

    int heigthTree(Tree* proot){
        if(proot){
            int lHeigth = heigthTree(proot->pLeft);
            int rHeigth = heigthTree(proot->pRight);
            if(lHeigth > rHeigth){
                return lHeigth + 1;
            }else{
                return rHeigth + 1;
            }
        }else{
            return 0;
        }
    }

    Tree* findMin(Tree* rt)
    {
        Tree* c = rt;
        while(c && c->pLeft != NULL)
            c = c->pLeft;
        return c;
    }

    Tree* DeleteTree(Tree* proot,int val){
        if(proot == NULL)
            return NULL;
        else if(val < proot->data)
            proot->pLeft = DeleteTree(proot->pLeft,val);
        else if(val > proot->data)
            proot->pRight = DeleteTree(proot->pRight,val);
        else{
            if(proot->pLeft == NULL && proot->pRight == NULL){
                delete proot;
                proot = NULL;
            }else if(proot->pLeft == NULL){
                Tree* temp = proot->pRight;
                delete proot;
                proot = temp;
            }else if(proot->pRight == NULL){
                Tree* temp = proot->pLeft;
                delete proot;
                proot = temp;
            }else{
                Tree* temp = findMin(proot->pRight);
                proot->data = temp->data;
                proot->pRight = DeleteTree(proot->pRight,proot->data);
            }
            return proot;
        }
    }
};

class TreeAVL{

public:
    Node* createNode(int data){
        Node* p;
        if(p == NULL){
            return NULL;
        }
        p->data = data;
        p->next = NULL;
        return p;
    }

    void init(Tree* &tree){
        tree = NULL;
    }

    int height(Tree* proot){
        if(proot){
            return proot->height;
        }else{
            return 0;
        }
    }

    Tree* createTree(int data){
        Tree* proot;
        proot->data = data;
        proot->pLeft = proot->pRight = NULL;
        proot->height = 1;
        return proot;
    }

    Tree* pRightRotate(Tree* y){
        Tree* x = y->pLeft;
        Tree* T2 = x->pRight;

        x->pRight = y;
        y->pRight = T2;

        x->height = max(height(x->pLeft), height(x->pRight)) + 1;
        y->height = max(height(y->pLeft), height(y->pRight)) + 1;
        return x;
    }

    Tree* pLeftRotate(Tree* y){
        Tree* x = y->pRight;
        Tree* T2 = x->pLeft;

        x->pRight = y;
        y->pRight = T2;

        x->height = max(height(x->pLeft), height(x->pRight)) + 1;
        y->height = max(height(y->pLeft), height(y->pRight)) + 1;
        return y;
    }

    // tim do chenh lech cua cay ( pLeft, pRight)
    int getBalance(Tree* t){
        if(t){
            return height(t->pLeft) - height(t->pRight);
        }else{
            return 0;
        }
    }

    Tree* insertTree(Tree* tree, int data){
        if (tree == NULL)
            return(createTree(data));

        if (data < tree->data)
            tree->pLeft = insertTree(tree->pLeft, data);
        else if (data > tree->data)
            tree->pRight = insertTree(tree->pRight, data);
        else
            return tree;

        tree->height = 1 + max(height(tree->pLeft),height(tree->pRight));
        int balance = getBalance(tree);
        if (balance > 1 && data < tree->pLeft->data)
            return pRightRotate(tree);

        if (balance < -1 && data > tree->pRight->data)
            return pLeftRotate(tree);

        if (balance > 1 && data > tree->pLeft->data){
            tree->pLeft = pLeftRotate(tree->pLeft);
            return pRightRotate(tree);
        }

        if (balance < -1 && data < tree->pRight->data){
            tree->pRight = pRightRotate(tree->pRight);
            return pLeftRotate(tree);
        }

        return tree;
}
    void NRL(Tree* proot){
        TreeBST t;
        t.NLR(proot);
    }
};

class queueNode{
public:
    bool isEmpty(queueN q){
        return q == NULL;
    }

    Node* createNode(int data){
        Node *P = new Node();
        if(P == NULL)
            return NULL;
        P->data = data;
        P->next = NULL;
    }

    int enQueue(queueN &q, int data){
        Node* p = createNode(data);
        if(q == NULL){
            q = p;
        }
        else{
            Node *ptr = q;
            while(ptr != NULL && ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = p;
        }
    }

    int peek(queueN q){
        if(!isEmpty(q)){
            return q->data;
        }else{
            cout << "Queue is empty!" << endl;
        }
    }

    int deQueue(queueN &q){
        if(!isEmpty(q)){
            int data = q ->data;
            Node* p = q;
            q = q->next;
            delete(p);
        return data;
        }else{
            return 0;
        }
    }
};

class stackNode{
public:

bool isEmpty(stackN s) {
    return (s == NULL);
}

Node* createNode(int data) {
    Node* p = new Node();
    if(p == NULL)
        return NULL;
    p->data = data;
    p->next = NULL;
    return p;
}

void push(stackN &s, int data) {
    Node* ptr = createNode(data);
    if(isEmpty(s))
        s = ptr;
    else {
        ptr->next = s;
        s = ptr;
    }
}

int top(stackN s) {
    if(!isEmpty(s))
        return s->data;
    else
        cout << "Stack is empty!" << endl;
}

int pop(stackN &s) {
    if(!isEmpty(s)) {
        int data = s->data;
        Node* x = s;
        s = s->next;
        delete(x);
        return data;
    } else
        cout << "Stack is empty!" << endl;
}
};

void menu(){
    cout << "-======data structure ======-" << endl;
    cout << "1. Node" << endl;
    cout << "2. Tree BST" << endl;
    cout << "3. Tree AVL" << endl;
    cout << "4. exit" << endl;
    cout << "-===========================-" << endl;
}

void menuNode(){
    cout << "-====== node ======-" << endl;
    cout << "01. insert node (first)" << endl;
    cout << "02. insert node (after)" << endl;
    cout << "03. insert node by array (first)" << endl;
    cout << "04. insert node by array (after)" << endl;
    cout << "05. print node" << endl;
    cout << "06. search node(return node)" << endl;
    cout << "07. search node(return position)" << endl;
    cout << "08. delete node (search)" << endl;
    cout << "09. delete node (position)" << endl;
    cout << "10. place" << endl;
    cout << "11. sort" << endl;
    cout << "12. clear node" << endl;
    cout << "13. exit" << endl;
}

void menuTreeBST(){
    cout << "-====== BST ======-" << endl;
    cout << "01. insert tree" << endl;
    cout << "02. insert tree (array)" << endl;
    cout << "03. NLR" << endl;
    cout << "04. LNR" << endl;
    cout << "05. LRN" << endl;
    cout << "06. search node" << endl;
    cout << "07. delete node (value)" << endl;
    cout << "08. count tree" << endl;
    cout << "09. leaf tree" << endl;
    cout << "10. heigth tree" << endl;
    cout << "11. sum tree" << endl;
    cout << "12. " << endl;
}

int main(){
    // -- call class
    LinkedList lk;
    TreeBST tBST;
    TreeAVL tAVL;
    // -- class struct
    Node* prootN;
    Tree* prootT = NULL;
    lk.init(prootN);
//
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    cout << "hello world, i'm hydra coder";
    do{
        menuNode();
        int choice;
        cin >> choice;
        switch(choice){
            case 1:{
                int data;
                cout << "value: ";
                cin >> data;
                tBST.addNode(prootT, data);
                break;
            }
            case 2:{
                int data;
                cout << "value: ";
                cin >> data;
                prootN = lk.insertAfter(prootN, data);
                break;
            }
            case 3:{
                tBST.NLR(prootT);
                break;
            }
            case 4:{
                int n;
                cout << "length: ";
                cin >> n;
                prootN = lk.insertAfter_Arr(prootN, n);
                break;
            }
            case 5:{
                toString(prootN);
                break;
            }
            case 6:{
                int target;
                cout << "value: ";
                cin >> target;
                Node* p = lk.searchList(prootN, target);
                if(p){
                    cout << "data: " << p->data << endl;
                }
                break;
            }
            case 7:{
                int target;
                cout << "value: ";
                cin >> target;
                int p = lk.position(prootN, target);
                cout << "position: " << p << endl;
                break;
            }

            case 13:{
                return 0;
            }
        }
        system("pause");
        system("cls");
    }while(1);
    return 0;
}

