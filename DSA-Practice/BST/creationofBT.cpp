#include <iostream>
#include <queue>
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

Node*buildBST(int val,Node* root){
    if(root == NULL){
        root = new Node(val);
        return root;
    }
        if(val < root->data){
            // val = left subtree mai dalo
            root->left = buildBST(val,root->left);
        }
        else{
            // val = right subtree mai dalo
            root->right = buildBST(val,root->right);
        }
    return root;
}

void preorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int getMin(Node* root){
    if(root == NULL){
        return -1;
    }
    while(root->left != NULL){
        root = root->left;
    }
    // iska matlab ki jab root left ke extreme pe pauch gaya hai
    return root->data;
}

int getMax(Node* root){
    if(root == NULL){
        return -1;
    }
    while(root->right != NULL){
        root = root->right;
    }
    // iska matlab ki jab root left ke extreme pe pauch gaya hai
    return root->data;
}

void createTree(Node* &root){
    cout <<"Enter the data for the root node: "<< endl;
     
    int val;
    cin >> val;

    while(val != -1){
        root = buildBST(val,root);
        cout <<"Enter the data for next node: " << endl;
        cin >> val;
    }
}

void levelordertraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << front->data << " ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);   
            }
        }
    }
}

bool SearchBST(Node* root,int target){
    if(root == NULL){
        return false;
    }
    if(root->data == target){
        return true;
    }
    else{
        // data target ke equal nhi hai(data!=target)
        // decide left jana hai ki right...kuyki hume time bacahana hai 
         if(target < root->data){
            // then hume left jaan hai
            bool leftAns = SearchBST(root->left,target);
            if(leftAns = true)
            return true;
         }
         else{
            // right jao
            bool rightAns = SearchBST(root->right, target);
            if(rightAns = true)
            return true;
         }
    }
    return false;
}

int main(){
    Node* root = NULL;
    createTree(root);
    levelordertraversal(root);

    cout << endl << "Inorder Traversal: ";
    inorderTraversal(root);

    cout << endl << "Preorder Traversal: ";
    preorderTraversal(root);

    cout << endl<< "Postorder Traversal: ";
    postorderTraversal(root);

    cout << endl <<"Min Element:" << getMin(root) << endl;
    cout << "max Element:" << getMax(root) << endl;

    bool searchAns = SearchBST(root, 253);

    if(searchAns)
        cout << "Node found" << endl;
    else
        cout << "Node not found" << endl;

    return 0;

}