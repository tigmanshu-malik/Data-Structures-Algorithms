#include<iostream>
#include<queue>
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

    node* remove(node* nodez, int value){

        if (nodez == nullptr)
            return nullptr;

        int data = nodez->data;
        if(data < value)
            nodez->right = remove(nodez->right, value); 

        else if(data > value)
            nodez->left = remove(nodez->left, value);

        else{

            if(nodez->left == nullptr && nodez->right == nullptr){

                delete nodez;
                return nullptr;
            }

            else if(nodez->left != nullptr && nodez->right == nullptr){

                node* temp = nodez->left;
                delete nodez;
                return temp;
            }

            else if(nodez->left == nullptr && nodez->right != nullptr){

                node* temp = nodez->right;
                delete nodez;
                return temp;
            }

            else{

                node* temp = nodez->left;
                while (temp->right != nullptr) {
                        temp = temp->right;
                }

                swap(nodez->data, temp->data);
                nodez->left = remove(nodez->left, temp->data);
 
            }
        }

        return nodez;        
    }

    void preorder(node* root){

        if(root == nullptr)
            return;

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);    
    }

    void inorder(node* root){

        if(root == nullptr)
            return;

        preorder(root->left);
        cout << root->data << " ";
        preorder(root->right);    
    }

    void postorder(node* root){

        if(root == nullptr)
            return;

        preorder(root->left);
        preorder(root->right);
        cout << root->data << " ";    
    }

    int height(node* root){

        if(root == nullptr)
            return 0;

        return max(height(root->left), height(root->right)) + 1;    
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

    bool remove(int value){

        if(contains(root, value)){

            remove(root, value);
            nodeCount--;
            return true;
        }

        else    
            return false;
    }

    void preorder(){

         preorder(root);
    }

    void inorder(){

        inorder(root);   
    }

    void postorder(){

        postorder(root)  ; 
    }

    void levelOrder(){

        queue<node*> q;

        q.push(root);

        node* temp;

        while(!q.empty()){

            temp = q.front();

            cout << temp->data << " ";

            if(temp->left != nullptr)
                q.push(temp->left);

            if(temp->right != nullptr)  
                q.push(temp->right);

            q.pop();      
        }

        cout << endl;
    }

    int height(){

        return height(root);
    }

};

int main(){

    bst tree;

    tree.insert(0);
    tree.insert(1);
    tree.insert(3);
    tree.insert(4);
    tree.insert(2);
    tree.insert(5);
    tree.insert(6);
    tree.levelOrder();
}