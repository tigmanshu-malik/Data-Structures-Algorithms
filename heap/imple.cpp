#include<iostream>
#include<vector>
using namespace std;

class minHeap{

private:
    
    vector<int> heap;

    int parent(int i){
        return (i - 1)/2;}

    int leftChild(int i){
        return (2*i + 1);
    }

    int rightChild(int i){
        return (2*i + 2);
    }

    void heapifyUp(int i){

        while(i > 0 && heap[parent(i)] > heap[i]){

            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void heapifyDown(int i){

        int minIndex = i;

        int left = leftChild(i);
        if (left < heap.size() && heap[left] < heap[minIndex])
            minIndex = left;

        int right = rightChild(i);
        if (right < heap.size() && heap[right] < heap[minIndex])
            minIndex = right;

        if(i != minIndex){

            swap(heap[i], heap[minIndex]);
            heapifyDown(minIndex);
        }        
    }

public:

    void insert(int value){

        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void min(){

        if(heap.size() == 0){
            cout << "Heap is empty !" << endl;
            return;
        }

        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();

        if(!heap.empty())
            heapifyDown(0);
    }

    void seek(){

        cout << heap[0] << endl;
    }    
    
};