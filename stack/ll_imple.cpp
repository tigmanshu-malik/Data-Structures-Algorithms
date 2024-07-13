#include<iostream>
using namespace std;

struct node {

    int data;
    node* next;

    node(int value) : data(value), next(nullptr) {}
};

node* start = nullptr;

void push(int value){

    node* temp = new node(value);

    temp->next = start;

    start = temp;
}

void pop(){

    if(start == nullptr){

        cout << "Stack Empty" << endl;
        return;
    }

    node* temp = start;

    start = start->next;

    delete temp;
}

void print(){

    if(start == nullptr){

        cout << "Stack Empty"<<endl;
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




