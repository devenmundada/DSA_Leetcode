#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode *> ans;
unordered_map<string, int> subTreeMap;
string preorder(TreeNode *root) {
  if (!root)
    return "N";

  string curr = to_string(root->val);
  string l = preorder(root->left);
  string r = preorder(root->right);
  string s = curr + "," + l + "," + r;

  if (subTreeMap.find(s) != subTreeMap.end()) {
    if (subTreeMap[s] == 1)
      ans.push_back(root);
    subTreeMap[s]++;
  } else {
    subTreeMap[s] = 1;
  }
  return s;
}

vector<TreeNode *> findDuplicateSubtree(TreeNode *root) {
  ans.clear();
  subTreeMap.clear();
  preorder(root);
  return ans;
}

int main() {
  {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->left->left = new TreeNode(4);

    vector<TreeNode *> duplicates = findDuplicateSubtree(root);
    for (TreeNode *node : duplicates) {
      cout << node->val << " ";
    }
    cout << endl;
  }
}