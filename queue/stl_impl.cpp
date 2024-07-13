#include<iostream>
#include<list>
using namespace std;

list<int> queue;

void enqueue(int value){

    queue.push_back(value);
}

int seek(){

    if(!queue.empty())
        return queue.front();

    return -1 ;   
}

void dequeue(){

    if(!queue.empty())
        queue.pop_front();
}