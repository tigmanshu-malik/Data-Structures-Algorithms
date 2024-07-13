#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;

    node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

node* start = nullptr;

void append(int value) {
    node* temp = new node(value);

    if (start == nullptr)
        start = temp;
    else {
        node* ptr = start;
        while (ptr->next != nullptr)
            ptr = ptr->next;
        ptr->next = temp;
        temp->prev = ptr;
    }
}

void insert(int value, int pos) {
    node* temp = new node(value);

    if (pos == 1) {
        temp->next = start;
        if (start != nullptr) {
            start->prev = temp;
        }
        start = temp;
        return;
    }

    node* ptr = start;
    int index = 1;

    while (ptr != nullptr && index < pos - 1) {
        ptr = ptr->next;
        index++;
    }

    if (ptr == nullptr) {
        cout << "Position is greater than the length of the list" << endl;
        delete temp;
        return;
    }

    temp->next = ptr->next;
    if (ptr->next != nullptr) {
        ptr->next->prev = temp;
    }
    temp->prev = ptr;
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

    node* ptr = start;

    while(ptr->data != value){

        ptr = ptr->next;

        if(ptr == nullptr){

            cout << "Not found !!!" << endl;
            return;
        }
    }

    if(ptr->next == nullptr){

        ptr->prev->next = nullptr;
        delete ptr;
        return;
    }

    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    delete ptr;
}

void print() {
    if (start == nullptr) {
        cout << "Linked List empty" << endl;
        return;
    }

    node* ptr = start;
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    for (int i = 0; i < 5; i++)
        append(i);

    print();

    remove(4);
    print();
}
