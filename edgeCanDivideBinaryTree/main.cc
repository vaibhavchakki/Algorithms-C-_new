/*
 * Check if removing an edge can divide a Binary Tree in two halves
 * Given a Binary Tree, find if there exist edge whose removal creates two trees of equal size.
 * 
 * Examples:
 * 
 * Input : root of following tree
 *            5
 *          /   \
 *        1      6    
 *       /      /  \
 *      3      7    4
 * Output : true
 * Removing edge 5-6 creates two trees of equal size
 * 
 * 
 * Input : root of following tree
 *            5
 *          /   \
 *        1      6    
 *             /  \
 *            7    4
 *          /  \    \
 *         3    2    8
 * Output : false
 * There is no edge whose removal creates two trees
 * of equal size.
 * http://www.geeksforgeeks.org/check-if-removing-an-edge-can-divide-a-binary-tree-in-two-halves/
 */
#include <iostream>
using namespace std;

struct Node {
    Node(int d):data(d),right(NULL),left(NULL) {}
  public:
    int   data;
    Node* right;
    Node* left;  
};


// 
// count number of nodes in a tree
int count(const Node* root) {
  if (root == NULL) {
    return 0;
  }

  return 1 + count(root->left) + count(root->right);
}

//
// helper function to detect if sub tree node count are same
// count nodes at each end and check if they match 
int checkRec(const Node* root, int numNodes, bool& res) {
  // if root is NULL, return 0
  if (root == NULL) {
    return 0;
  }

  // calculate number of nodes at the leaf
  int c = 1 + checkRec(root->left, numNodes, res) +
              checkRec(root->right, numNodes, res);

  // if leaf node count equals the remaning node count
  // set return result to true
  if ( c == (numNodes - c) ) {
    res = true;
  }
 
  // return number of nodes in this subtree
  return c;
}


bool check(const Node* root) {
  int numNodes = count(root);
  bool res = false;

  checkRec(root, numNodes, res);

  return res;
}

int main(int argc, const char** argv) {
  Node* root = new Node(5);
  root->left = new Node(1);
  root->right = new Node(6);
  root->left->left = new Node(3);
  root->right->left = new Node(7);
  root->right->right = new Node(4);

  cout << (check(root) ? "Yes" : "No") << endl;
  return 0;
}
