/*
 * Check if leaf traversal of two Binary Trees is same?
 * Leaf traversal is sequence of leaves traversed from left to right. The problem is 
 * to check if leaf traversals of two given Binary Trees are same or not.
 * Expected time complexity O(n). Expected auxiliary space O(h1 + h2) where h1 and h2 
 * are heights of two Binary Trees.
 * Input: Roots of below Binary Trees
 *        1            
 *       / \
 *      2   3      
 *     /   / \
 *    4   6   7
 *
 *       0
 *      /  \
 *     5    8        
 *      \  / \
 *      4  6  7
 * Output: same
 * Leaf order traversal of both trees is 4 6 7       
 *
 * Input: Roots of below Binary Trees
 *       0            
 *      / \
 *     1   2       
 *    / \
 *   8   9   
 *
 *       1
 *      / \
 *     4   3       
 *      \ / \
 *      8 2  9
 *
 * Output: Not Same
 * Leaf traversals of two trees are different.
 * For first, it is 8 9 2 and for second it is
 * 8 2 9
 *
 * http://www.geeksforgeeks.org/check-if-leaf-traversal-of-two-binary-trees-is-same/
 */

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    Node(int d):data(d),right(NULL),left(NULL){}
  public:
    int   data;
    Node* right;
    Node* left;
};

//
// check if two vectors are same
bool isListSame(const vector<int>& l1, const vector<int>& l2) {
  // return false if size of vectors are not same
  if (l1.size() != l2.size()) {
    return false;
  }

  //
  // check each element of vector and if not same
  // return false
  for (int it = 0; it < l1.size(); it++) {
    if (l1[it] != l2[it]) {
      return false;
    }
  }

  // return true, all elements are same
  return true;
}

void getLeafList(Node* root, vector<int>& l) {
  // if null, no need to add, just return
  if (root == NULL) {
    return;
  }
  else if ((root->left == NULL) && (root->right == NULL)) {
    // this is a leaf node, add it back of the list
    l.push_back(root->data);
  }
  
  // now explore left tree
  if (root->left) {
    getLeafList(root->left, l);
  }
  // now explore right tree
  if (root->right) {
    getLeafList(root->right, l);
  }
}

bool isSame(Node* root1, Node* root2) {
  // declare two lists
  vector<int> l1 = vector<int>(); 
  vector<int> l2 = vector<int>(); 

  // get list l1 for root1
  getLeafList(root1, l1);
  // get list l2 for root2
  getLeafList(root2, l2);

  // check if lists l1 and l2 are same
  return isListSame(l1, l2);
}


int main(int argc, const char** argv) {
  Node* root1         = new Node(1);
  root1->left         = new Node(2);
  root1->right        = new Node(3);
  root1->left->left   = new Node(4);
  root1->right->left  = new Node(6);
  root1->right->right = new Node(7);

  Node* root2         = new Node(0);
  root2->left         = new Node(1);
  root2->right        = new Node(5);
  root2->left->right  = new Node(4);
  root2->right->left  = new Node(6);
  root2->right->right = new Node(7);

  cout << (isSame(root1, root2) ? "Same" : "Not Same") << endl;

  return 0;
}
