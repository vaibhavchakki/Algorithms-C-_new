/*
 * 
 * Write a program that converts a given tree to its Double tree. To create Double tree of the given t
 * ree, create a new duplicate for each node, and insert the duplicate as the left child of the original node.
 *
 * So the tree…
 *
 *   2
 *  / \
 * 1   3
 * is changed to…
 *       2
 *      / \
 *     2   3
 *    /   /
 *   1   3
 *  /
 * 1
 * And the tree
 *
 *           1
 *         /   \
 *       2      3
 *     /  \
 *    4     5
 * is changed to
 *              1
 *            /   \
 *          1      3
 *         /      /
 *       2       3
 *     /  \
 *    2    5
 *   /    /
 *  4   5
 * /   
 *4    
 * Algorithm:
 * Recursively convert the tree to double tree in postorder fashion. For each node, first convert the 
 * left subtree of the node, then right subtree, finally create a duplicate node of the node and fix 
 * the left child of the node and left child of left child.
 * http://www.geeksforgeeks.org/double-tree/
 */
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int d):data(d), left(NULL), right(NULL) {}
};

void doubleTree(Node* root) {
  if (NULL == root) {
    return;
  }

  doubleTree(root->left);
  doubleTree(root->right);

  Node* old = root->left;
  root->left = new Node(root->data);
  root->left->left = old;
}

void printTree(Node* n) {
  if (NULL == n) {
    return;
  }
  printTree(n->left);
  cout << n->data << " ";
  printTree(n->right);
}

int main() {
 Node* root = new Node(2);
 root->left = new Node(1);
 root->right = new Node(3);

 doubleTree(root);

 printTree(root);
 cout << endl;

 return 0;
}

