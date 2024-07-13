#include<iostream>
using namespace std;

struct node {

    int data;
    node* next;

    node(int value) : data(value), next(nullptr) {}
};

node* start = nullptr;

void append(int value){

    node* temp = new node(value);

    if(start == nullptr)
        start = temp;

    else{

        node* ptr = start;

        while(ptr->next != nullptr)
            ptr = ptr->next;

        ptr->next = temp;    
    }    
}

void insert(int position, int value){

    int index = 1;

    node* ptr = start;
    node* temp = new node(value);

    if(position == 1){

        temp->next = ptr;
        start = temp;
        return;
    }

    while(ptr->next != nullptr){

        if(index == position - 1)
            break;

        ptr = ptr->next;
        index++;    
    }

    temp->next = ptr->next;

    ptr->next = temp;

}

void remove(int value){

    if(start->data == value){

        node* temp = start;
        start = start->next;
        delete temp;
        return;
    }

    else if(start->data != value && start->next == nullptr){

        cout << "Not found !!!" << endl;
        return;
    }

    node* trav1 = start;
    node* trav2 = start->next;

    while(trav2->data != value){

        trav1 = trav2;
        trav2 = trav2->next;

        if(trav2 == nullptr){

        cout << "Not found !!!" << endl;
        return;
        }
    }

    node* temp = trav2;
    trav1->next = trav2->next;
    delete temp;

}

void print(){

    if(start == nullptr){

        cout << "Linked List empty"<<endl;
        return;
    }

    else{

        node* ptr = start;

        while(ptr->next != nullptr){
            cout << ptr->data << " ";
            ptr = ptr->next;
            }

        cout << ptr->data << endl;    
    }
}

int main(){

    for(int i = 0 ; i < 5; i++)
        append(i);

    print();    

    remove(44);    

    print();
}


