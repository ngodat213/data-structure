#include<bits/stdc++.h>
using namespace std;

string th = "0123456789";
string tt = "+-*/^";

struct Node{
    int data;
    Node* next;
};

Node* createNode(int data){
    Node* node;
    node->data = data;
    node->next = nullptr;
    return node;
}

Node* push(Node* node, int data){
    Node* p = createNode(data);
    if(node == nullptr){
        return p;
    }else{
        p->next = node;
        node = p;
    }
    return p;
}

int pop(Node* &node){
    if(node != nullptr){
        int data = node->data;
        Node* x = node;
        node = node->next;
        delete(x);
        return data;
    }else{
        cout << "stack is empty!\n";
    }
}

bool isTT(char c){
    for(int i = 0; i < tt.length(); ++i){
        if(c == tt[i]){
            return 1;
        }
    }
    return 0;
}

bool isTH(char c){
    for(int i = 0; i < th.length(); ++i){
        if(c == th[i]){
            return 1;
        }
    }
    return 0;
}

double op(int a, int b, char c){
    switch(c){
        case '-':{
            return a-b;
            break;
        }
        case '+':{
            return a+b;
            break;
        }
        case '*':{
            return a*b;
            break;
        }
        case '/':{
            return 1.0*a/b;
            break;
        }
        case '^':{
            return pow(a,b);
            break;
        }
    }
}

double oprator(string s){
    double res = 0;
    Node* p;
    for(int i = 0; i < s.length(); ++i){
        if(isTH(s[i])){
            push(p, stoi(s[i]));
        }
        if(isTT(s[i])){
            int a = pop(p);
            int b = pop(p);
            res += op(b,a, s[i]);
            push(p, res);
        }
    }
    return pop(p);
}

int main(){
    string s = "62/3+74-*"
    cout << oprator(s);
    return 0;
}
