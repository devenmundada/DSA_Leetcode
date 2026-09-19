#include <ios>
#include <iostream>

using namespace std;

struct Treenode{
    int val;
    Treenode* left;
    Treenode* right;
};

class Solution{
    public:

    int maxDepth(Treenode* root){
    // Base case
        if(root == NULL)
        return 0;

    int leftsubtree = maxDepth(root->left);
    int rightsubtree = maxDepth(root -> right);
    int maxheight = max(leftsubtree,rightsubtree);
    return max(leftsubtree,rightsubtree) + 1;
    }
};

int main(){
    
}