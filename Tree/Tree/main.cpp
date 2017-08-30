//
//  main.cpp
//  Tree
//
//  Created by Vaibhav Chakki on 8/29/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <iostream>
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

int main(int argc, const char * argv[]) {
    
    Node* root = NULL;
    insert(&root, 1);
    insert(&root, 4);
    insert(&root, 5);
    insert(&root, 7);
    insert(&root, 9);
    
    inOrder(root);
    
    printAncestors(root, 7);

    return 0;
}
