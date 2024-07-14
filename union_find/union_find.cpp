#include<iostream>
using namespace std;

class unionFind{

private:

    int* id;

public:

    unionFind(int elements){

    if(elements <= 0){

        cout << "elements can't be negative idiot "<< endl;
        return;
    }

    id = new int[elements];

    for(int i = 0; i < elements; i++){

        id[i] = i;
    }

    for(int i = 0; i < elements; i++){
        cout << id[i] << " ";
    }
}   
     ~unionFind() {
        delete[] id;
    }

    int find(int p){

        int root = p;

        while(id[root] != root)
            root = id[root];

        while(p != root){

            int next = id[p];
            id[p] = root;
            p = next;
        }

        return root;  
    }

    bool isConnected(int p, int q){

        return find(p) == find(q);
    }

    void merge(int p, int q){

        int root1 = find(p);
        int root2 = find(q);

        if(root1 == root2)
            return;

        id[root1] = root2;    
    }



};
