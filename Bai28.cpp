#include<iostream>
using namespace std;


// Linked list
class Node
{
public:
    int data;
    Node* next;

    void init(Node* &pHead)
    {
        pHead = NULL;
    }

    bool isEmpty(Node* node)
    {
        return node == NULL;
    }

    int listSize(Node* node)
    {
        int cnt = 0;
        Node* p = node;
        while(!isEmpty(p))
        {
            cnt++;
            p=p->next;
        }
        return cnt;
    }

    Node* retrieve(Node* node, int pos)
    {
        if(isEmpty(node) || pos < 0)
        {
            cout << "no info!" << endl;
        }
        else
        {
            int cnt = 0;
            Node* p = node;
            while(!isEmpty(node) && cnt < pos)
            {
                p=p->next;
                cnt++;
            }
            return p;
        }
    }

    Node* createNode(int data)
    {
        Node* p;
        if(isEmpty(p))
        {
            return NULL;
        }
        p->data = data;
        p->next = NULL;
        return p;
    }

    Node* insertHead(Node* node, int data)
    {
        Node* p = createNode(data);
        if(isEmpty(node))
        {
            node = p;
        }
        else
        {
            p->next = node;
            node = p;
        }
        return node;
    }

    Node* insertAfter(Node* node, int data){
        Node* p = createNode(data);
        if(!isEmpty(node)){
            p->next = node->next;
            node->next = p;
        }
        return node;
    }

    Node* insertTail(Node* node, int data)
    {
        Node* temp;
        Node* p = createNode(data);
        if(isEmpty(node))
        {
            node = p;
        }
        else
        {
            temp = node;
            while(!isEmpty(temp->next))
            {
                temp = temp->next;
            }
            temp->next = p;
        }
    }

    Node* deleteFirst(Node* node){
        Node* p = node;
        if(isEmpty(node)){
            cout << "node is empty!" << endl;
        }else{
            node = node->next;
            delete p;
        }
        return node;
    }

    Node* deleteAfter(Node* node){
        Node* p;
        if(isEmpty(node) || isEmpty(node->next)){
            cout << "cannot delete node!" << endl;
        }else{
            p = node->next;
            node->next = p->next;
            delete p;
        }
        return node;
    }

    Node* clearList(Node* node){
        Node* p;
        while(!isEmpty(node)){
            node = deleteFirst(node);
        }
    }

    void display(Node* node){
        Node* p = node;
        while(!isEmpty(p)){
            cout << p->data << " ";
            p = p->next;
        }
    }

    Node* searchNode(Node* node, int index){
        Node* p = node;
        while(p->data != index || isEmpty(p)){
            p = p->next;
        }
        return p;
    }

    Node* sortNode(Node* node){
        Node* i, *j;
        for(i = node; !isEmpty(i->next); i=i->next){
            for(j = node->next; !isEmpty(j->next); j=j->next){
                if(i->data > j->data){
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
        return node;
    }

    int posNode(Node* pHead, Node* node){
        int pos = 0;
        Node* p = pHead;
        while(!isEmpty(p) && p != node){
            p = p->next;
            pos++;
        }
        if(isEmpty(p)){
            return -1;
        }
        return pos;
    }

    Node* preNode(Node* pHead, Node* node){
        Node* p;
        if(isEmpty(node)){
            return NULL;
        }
        p = pHead;
        while(!isEmpty(p) && p->next != node){
            p = p->next;
        }
        return p;
    }

};

class Tree{ //BST
public:
    int data;
    Node* pLeft9
    Node* pRight;

};

int main()
{

    return 0;
}
