/*
 * Connect nodes at same level using constant extra space
 * Write a function to connect all the adjacent nodes at the same level in a binary tree. 
 * Structure of the given Binary Tree node is like following.
 * 
 *  struct node {
 *  int data;
 *  struct node* left;
 *  struct node* right;
 *  struct node* nextRight;
 * }
 *
 * Example
 * Input Tree
 *       A
 *      / \
 *     B   C
 *    / \   \
 *   D   E   F
 * 
 * Output Tree
 *       A--->NULL
 *      / \
 *     B-->C-->NULL
 *    / \   \
 *   D-->E-->F-->NULL
 */
#include <iostream>
using namespace std;

struct Node {
  int   data;
  Node* left;
  Node* right;
  Node* nextRight;

  Node(int d):data(d), left(NULL), right(NULL), nextRight(NULL) {}
};

void connect(Node* p) {
  if (NULL == p) {
    return;
  }

  if (p->left) {
    p->left->nextRight = p->right;
   
    if (p->right && p->nextRight) {
      p->right->nextRight = p->nextRight->left;
    }
  }


  connect(p->left);
  connect(p->right);
}

int main(int argc, const char** argv) {
  /* Constructed binary tree is
            10
           /   \
         8      2
        /         \
      3            90
  */
  Node *root = new Node(10);
  root->left        = new Node(8);
  root->right       = new Node(2);
  root->left->left  = new Node(3);
  root->right->right       = new Node(90);
 
  // Populates nextRight pointer in all nodes
  connect(root);
 
  // Let us check the values of nextRight pointers
  printf("Following are populated nextRight pointers in the tree "
         "(-1 is printed if there is no nextRight) \n");
  printf("nextRight of %d is %d \n", root->data,
         root->nextRight? root->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->data,
         root->left->nextRight? root->left->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->right->data,
           root->right->nextRight? root->right->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->left->data,
         root->left->left->nextRight? root->left->left->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->right->right->data,
         root->right->right->nextRight? root->right->right->nextRight->data: -1);
  return 0;
}
