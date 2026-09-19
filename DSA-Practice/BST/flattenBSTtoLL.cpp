#include <iostream>

using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Autility function to create a new BST node
struct node *newNode(int item) {
  struct node *temp = new struct node;
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}
// A utility function to insert
// a new node with given key in BST
struct node *insert(struct node *node, int key) {
  // if tree is empty
  if (node == NULL)
    return newNode(key);
  // otherwise search down the tree
  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);

  // return the unchanged pointer
  return node;
}

// utility fuction to search key in BST
struct node *search(struct node *root, int key) {
  // base case
  if (root == NULL || root->key == key)
    return root;

  // key is greater than roots key
  if (root->key < key)
    return search(root->right, key);

  return search(root->left, key);
}

void printLL(node *head) {
  while (head) {
    cout << head->key << " ";
    head = head->right;
  }
}

void in(node *root, node *&prev) {
  if (!root)
    return;
  in(root->left, prev);
  cout << root->key << " ";
  in(root->right, prev);
}

node *flatten(node *root) {
  node *dummy = newNode(-1);
  node *prev = dummy;
  in(root, prev);
  prev->left = prev->right = 0;
  root = dummy->right;
  return root;
}

int main() {
  struct node *root = NULL;
  root = insert(root, 5);
  insert(root, 3);
  insert(root, 2);
  insert(root, 4);
  insert(root, 7);
  insert(root, 6);
  insert(root, 8);
  root = flatten(root);
  printLL(root);
  return 0;
}
