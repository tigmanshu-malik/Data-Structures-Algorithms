#include<iostream>
using namespace std;

#define max 5
int queue[max]; 

int front = -1;
int back = -1;

void enqueue(int value){

    if(front == -1){
        front = 0;
        back = 0;
        queue[back] = value;
        return;
    }

    if(back == max - 1){

        if(front == 0){
            cout << "Queue is full" << endl;
            return;
        }

        back = 0;
        queue[0] = value;
        return;
    }

    else if(back + 1 == front){

        cout << "Queue is full" << endl;
        return;
    }

    queue[++back] = value;  

}

int seek(){

    return queue[front];
}

void dequeue(){

    if(front == -1 ){

        cout << "Queue empty" << endl;
        return;
    }

    if(front == max - 1){
        front = 0;
        return;
    }

    else if(front == max){

        front = -1;
        back = -1;
    }

    front++;    
}

void print(){

    int i = front;

    while(i != back){

        cout << queue[i] << " ";
        i++;

        if(i == max){
                i = 0;
    } 
    }
    cout << queue[i] << endl;
}

int main(){

    for(int i = 1; i <= 5; i++)
        enqueue(i);

    dequeue();
    dequeue();
    dequeue();
    cout << "front -> " << front <<" back -> " << back <<endl;

    print();

    enqueue(6);
    cout << "front -> " << front <<" back -> " << back <<endl;
    enqueue(7);
    cout << "front -> " << front <<" back -> " << back <<endl;
    enqueue(8);
    cout << "front -> " << front <<" back -> " << back <<endl;
    enqueue(9);

    print();
}