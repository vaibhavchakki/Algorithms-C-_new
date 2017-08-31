//
//  main.cpp
//  Tree
//
//  Created by Vaibhav Chakki on 8/29/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int d):data(d), left(NULL), right(NULL) {}
};

void preOrder(Node *root) {
    if (root) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
    
}

void inOrder(Node *root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int height(Node * root)
{
    // This counts the number of edges
    // if count number of nodes , return 0, instead of -1
    if (root == NULL) {
        return -1;
    }
    
    return max(height(root->left), height(root->right)) + 1;
}

void top_view(Node * root)
{
    if ( root && (root->left || root->right) ) {
        top_view(root->left);
        cout << root->data << " ";
        top_view(root->right);
    }
}

/*
 * insert node in binary tree
 */
void insert(Node** root, int d) {
    
    Node* n = *root;
    
    if (NULL == n) {
        n = new Node(d);
    }
    else if (n->data > d) {
        insert(&n->left, d);
    }
    else {
        insert(&n->right, d);
    }
    
    *root = n;
}

/*
 * This function is to print the Ancestors based on the node
 * http://www.geeksforgeeks.org/print-ancestors-of-a-given-node-in-binary-tree/
 */
bool printAncestors(Node* root, int target) {
    if (NULL == root) {
        return false;
    }
    
    if (root->data == target) {
        return true;
    }
    
    if (printAncestors(root->left, target) ||
        printAncestors(root->right, target)) {
        cout << root->data << endl;
        return true;
    }
    
    return false;
}

/*
 * Root to leaf path sum equal to a given number Given a binary tree and a 
 * number, return true if the tree has a root-to-leaf path such that adding
 * up all the values along the path equals the given number. Return false if
 * no such path can be found.
 * http://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/
 */
bool rootToLeafPathSum(Node* root, int target) {
    
    if (NULL == root) {
        return (target == 0);
    }
    
    int sum = target - root->data;
    
    if (!root->left && !root->right && (sum == 0) ) {
        return true;
    }
    
    if ( rootToLeafPathSum(root->left, sum) ||
         rootToLeafPathSum(root->right, sum) ) {
        return true;
    }
    
    return false;
}

/*
 * Given a binary tree, print level order traversal in a way that 
 * nodes of all levels are printed in separate lines.
 * http://www.geeksforgeeks.org/print-level-order-traversal-line-line/
 */
void printLevelOrder(Node* root) {
    
    if (NULL == root) {
        return;
    }
    
    queue <Node* > q;
    q.push(root);
    
    while (1) {
        
        size_t nodeCount = q.size();
        
        if (nodeCount == 0) {
            break;
        }
        
        while (nodeCount > 0) {
            Node *n = q.front();
            cout << n->data << " ";
            q.pop();
            
            if (n->left) {
                q.push(n->left);
            }
            
            if (n->right) {
                q.push(n->right);
            }
            
            nodeCount--;
        }
        
        cout << endl;
        
    }
}


int main(int argc, const char * argv[]) {
    
    Node* root = NULL;
    insert(&root, 1);
    insert(&root, 4);
    insert(&root, 5);
    insert(&root, 7);
    insert(&root, 9);
    
    //inOrder(root);
    
    //printAncestors(root, 7);
    
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->right = new Node(6);
    printLevelOrder(root1);
    

    return 0;
}
