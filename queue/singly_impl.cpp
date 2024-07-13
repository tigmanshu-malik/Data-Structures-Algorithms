#include<iostream>
using namespace std;

struct node{

    int data;
    node* next;
    node(int value) : data(value), next(nullptr) {};
};

node* start = nullptr;
node* tail = nullptr;

void enqueue(int value){

    node* temp = new node(value);

    if(start == nullptr && tail == nullptr){

        start = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    tail = temp;
}

void dequeue(){

    if(start == nullptr){

        cout << "Queue empty" << endl;
        return;
    }

    if(start == tail){

        delete start;
        start = nullptr;
        tail = nullptr;
        return;
    }

    node* temp = start;
    start = start->next;
    delete temp;
}