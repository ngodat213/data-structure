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

typedef struct Node* Queue;

Queue queueData;

void init(Queue &queue){
    queue = NULL;
}

bool isEmpty(Queue st){
    return st == NULL;
}

bool isID(int id){
    Queue p = queueData;
    while(!isEmpty(p)){
        if(p->data.id == id){
            return 0;
        }
    }
    return 1;
}

Item inputItem(){
    Item item;
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

void showList(Queue stack){
    Queue temp = stack;
    while(temp != NULL){
        outputItem(temp->data);
        temp = temp->next;
    }
}


Queue createQueue(Item item){
    Node* st = new Node;
    if(st == NULL){
        return NULL;
    }
    st->data = item;
    st->next = NULL;
    return st;
}

void enQueue(Queue &q, Item data){
    Node* p = createQueue(data);
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

Item peek(Queue q){
    if(!isEmpty(q)){
        return q->data;
    }else{
        cout << "Queue is empty!" << endl;
    }
}

Item deQueue(Queue &q){
    if(!isEmpty(q)){
        Item data = q ->data;
        Node* p = q;
        q = q->next;
        delete(p);
        return data;
    }else{
        cout << "queue is empty!\n";
    }
}

Item find_id(Queue queue, int id){
    Queue temp = queue;
    while(temp != NULL){
        if(temp->data.id == id){
            return temp->data;
        }
        temp = temp->next;
    }
}

Item find_name(Queue queue, string name){
    Queue temp = queue;
    while(temp != NULL){
        if(temp->data.name == name){
            return temp->data;
        }
        temp = temp->next;
    }
}

Item del_id(Queue queue, int id){
    Queue temp = queue;
    while(temp);
}

void menu(){
    cout << "1. insert item\n";
    cout << "2. show item\n";
    cout << "3. find item by id\n";
    cout << "4. find item by name\n";
    cout << "5. delete item by name\n";
    cout << "6. delete item by id\n";
}

int main(){
    do{
        menu();
        int choice;
        cin >> choice;
        switch(choice){
            case 1:{
                Item item = inputItem();
                enQueue(queueData, item);
                break;
            }
            case 2:{
                showList(queueData);
                break;
            }
            case 3:{

                break;
            }
        }
    }while(1);
    return 0;
}
