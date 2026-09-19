#include  <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

Node* findpredecessor(Node* root,Node* p){
    Node* pred = 0;
    Node* curr = root;

    while (curr){  //jab tak current element hai
    if(curr -> data < p -> data){
        pred = curr;
        curr = curr -> right;
    }
    else{
        curr = curr->left;
    }
  }
  return pred;
}

Node* insert(Node* root,int val){
    if(!root)
    return new Node(val);
    if(val < root->data)
    root->left = insert(root->left,val);
    else
    root->right = insert(root->right,val);

    return root;
}

int main(){
    Node* root = NULL;
    root = insert(root,20);
    insert(root,3);
    insert(root,4);
    insert(root,2);
    insert(root,1);
    insert(root,7);
    insert(root,6);
    insert(root,9);
    insert(root,8);
    insert(root,10);

    Node* p = root;

    Node* pred = findpredecessor(root,p);

    if(pred)
    cout << "Predeseccor of " << p->data << " is: " << pred->data << endl;
    else
    cout << "No predecessor found for" << p->data << endl;

    return 0;
}