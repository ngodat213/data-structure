#include<iostream>
using namespace std;

struct Item{
    int id;
    string name;
    int cnt;
};

struct Node{
    Item data;
    Node* next;
};

typedef struct Node* Stack;

Stack stackData;

void init(Stack &stack){
    stack = NULL;
}

bool isEmpty(Stack st){
    return st == NULL;
}

Stack createStack(Item item){
    Node* st = new Node;
    if(st == NULL){
        return NULL;
    }
    st->data = item;
    st->next = NULL;
    return st;
}

void push(Stack &st, Item item){
    Stack p = createStack(item);
    if(isEmpty(st)){
        st = p;
    }
    p->next = st;
    st = p;

}

Item top(Stack st){
    if(isEmpty(st)){
        cout << "stack is empty!\n";
    }
    return st->data;
}

Item pop(Stack &st){
    if(isEmpty(st)){
        cout << "stack is empty!\n";
    }else{
        Item result = st->data;
        Node* p = st;
        st = st->next
        delete p;
        return result;
    }
}

bool isID(int id){
    Stack p = stackData;
    while(!isEmpty(p)){
        if(p->data.id == id){
            return 0;
        }
    }
    return 1;
}

Item inputItem(){
    Item item = new Item;
    do{
        cout << "id: ";
        cin >> item.id;
        cout << "name: ";
        cin.ignore();
        getline(cin, item.name);
        cout << "cnt: ";
        cin >> item.cnt;
    }while(!isID(item.id));
    return item;
}

void outputItem(Item item){
    printf("item={id=%d, name=\'%s\', cnt=%d}\n", item.id, item.name.c_str(), item.cnt);
}

void menu(){
    cout << "insert item\n";
    cout << "show item\n";
    cout << "find item by id\n";
    cout << "find item by name\n";
    cout << "delete item by name\n";
    cout << "delete item by id\n";
}

int main(){
    return 0;
}
