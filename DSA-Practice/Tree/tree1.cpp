#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        this -> data = val;
        left = NULL;
        right = NULL;
    }
};

Node* CreateTree(){
    // cout << "Enter the value of Node:" ;
    int value;
    cin >> value;

    if(value == -1){
        return NULL;
    }
    else{
        // invalid value
        Node* root = new Node(value);
        // 1 case mai karunga baki nodes recursion dekh lenga
        // cout << "adding left child for:" << value << endl;
        root -> left = CreateTree();
        // cout <<"adding right child for:" << value << endl;
        root -> right = CreateTree();
        return root;
    }
}

void preOrderTraversal(Node* root){
        if(root ==  NULL){
            return;
        }
        // NLR
        // N
        cout << root -> data << endl;
        // L -> Left traversa;
        preOrderTraversal(root -> left);
        // R -> right traversal
        preOrderTraversal(root -> right);
}

void inOrderTraversal(Node* root){
        if(root  == NULL){
            return;
        }
        // LNR
        // L -> left traversal first
        inOrderTraversal(root -> left);
        // N -> Node
        cout << root -> data << " ";
        // R -> right order traversl
        inOrderTraversal(root -> right);
}

void PostOrderTraversal(Node* root){
    if(root == NULL)
    {
        return;
    }
    // LNR
    // Left
    PostOrderTraversal(root -> left);
    // Right
    PostOrderTraversal(root -> right);
    // Node
    cout << root -> data << " ";
}

void levelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    // intial state maintain
    q.push(root);
    q.push(NULL);
    
    // logic -> steps A,B,C
    while(!q.empty()){
        // queue se nikalo
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            // iska matlab current level complete hogya hai
            cout << endl;
            // Lakin ye toh bas ek level ke liye hai
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            // fer print karalo
        cout << front -> data << " ";

        // Iske bache khaa lo 
        // Khaa lo means -> queue mai insert kar na
        if(front -> left != NULL){
            q.push(front->left);
        }
        if(front -> right != NULL){
            q.push(front -> right);
        }
    }
  } 
}

        

int main(){

    Node* root;
    root = CreateTree();

    levelOrderTraversal(root);

    // cout << "Printing root:" << root->data << endl;
    return 0;
}