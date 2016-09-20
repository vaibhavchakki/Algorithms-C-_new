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

int main(int argc, const char * argv[]) {

    return 0;
}
