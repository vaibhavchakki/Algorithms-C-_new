/*
 * Find multiplication of sums of data of leaves at same levels
 * Given a Binary Tree, return following value for it.
 * 1) For every level, compute sum of all leaves if there are leaves at this level. Otherwise ignore it.
 * 2) Return multiplication of all sums.
 * 
 * Examples:
 * 
 * Input: Root of below tree
 *          2
 *        /   \
 *       7     5
 *              \
 *               9
 * Output: 63
 * First levels doesn't have leaves. Second level
 * has one leaf 7 and third level also has one 
 * leaf 9.  Therefore result is 7*9 = 63
 * 
 *  Input: Root of below tree
 *          2
 *        /   \
 *      7      5
 *     / \      \
 *    8   6      9
 *       / \    /  \
 *      1  11  4    10 
 * 
 * Output: 208
 * First two levels don't have leaves. Third
 * level has single leaf 8. Last level has four
 * leaves 1, 11, 4 and 10. Therefore result is 
 * 8 * (1 + 11 + 4 + 10)  
 * 
 * http://www.geeksforgeeks.org/find-multiplication-of-sums-of-data-of-all-leaves-at-sane-levels/
 */

#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int d):data(d), left(NULL), right(NULL) {}
};

int sumAndMultiplyLevelData(Node* root) {
  if (NULL == root) {
    return 0;
  }

  int prod = 1;
  queue<Node*> Q;

  Q.push(root);

  while (Q.size() > 0) {
    int sum = 0;
    int isleaf = false;

    int size = Q.size();

    while (size > 0) {
      Node* p = Q.front();
   
      if ((p->left == NULL) && (p->right == NULL)) {
        isleaf = true;
        sum += p->data;
      }
      Q.pop();
      
      if (p->left) {
        Q.push(p->left);
      }
      if (p->right) {
        Q.push(p->right);
      }
      size--;
    }
    
    if (isleaf) {
      prod = prod * sum;
    }
  }

  return prod;
}


int main() {
  Node* root = new Node(2);
  root->left = new Node(7);
  root->right = new Node(5);
  root->right->right = new Node(9);

  cout << "Ans is: " << sumAndMultiplyLevelData(root) << endl;

  return 0;
}
