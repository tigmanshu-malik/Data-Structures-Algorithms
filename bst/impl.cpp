#include<iostream>
using namespace std;

struct node{

    int data;
    node* left;
    node* right;

    node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class bst{

private:

    int nodeCount = 0;
    node* root = nullptr;

    node* add(node* nodez, int data){

        if(nodez == nullptr)
            nodez = new node(data);

        else{

            if(data > nodez->data)
                nodez->right = add(nodez->right, data);

            else 
               nodez->left =  add(nodez->left, data);    
        }

        return nodez;   
    }

    bool contains(node* node, int value){

        if(node == nullptr)
            return false;

        else{

            if(value > node->data)
                return contains(node->right, value);

            else if(value < node->data)    
                return contains(node->left, value);

            else
                return true;    
        }    
    }

public:

    bool isEmpty(){

        return nodeCount == 0;
    }

    bool insert(int value){

        if(root == nullptr){

            root = new node(value);
            nodeCount++;
            return true;
        }

        else{

            if(!contains(root, value)){

                root = add(root, value);
                nodeCount++;
                return true;
            }

            else{
                return false;
            }
        }
    }
};