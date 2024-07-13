#include<iostream>
#include<list>
using namespace std;

list<int> stack;

void push(int value){

    stack.push_front(value);
}

void pop(){

    if(stack.empty()){

        cout << "Stack is empty" << endl;
        return;
    }

    stack.pop_front();
}

int seek(){

    if(stack.empty())
        return -1;

    return stack.front();   
}