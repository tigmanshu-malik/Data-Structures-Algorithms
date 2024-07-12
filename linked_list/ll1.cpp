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

void print(){

    if(start == nullptr){

        cout << "Linked List empty"<<endl;
        return;
    }

    else{

        node* ptr = start;

        while(ptr->next != nullptr)
            cout << ptr->data << " ";

        cout << ptr->data << endl;    
    }
}

