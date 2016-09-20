//
//  main.cpp
//  BinaryTree
//
//  Created by Vaibhav Chakki on 8/27/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node {
    int d;
    Node* l;
    Node* r;
    Node(int data):d(data), l(NULL), r(NULL) {}
};

void insert(Node** root, int d)
{
    if (*root == NULL) {
        *root = new Node(d);
    }
    else if ((*root)->d < d) {
        insert(&(*root)->l, d);
    }
    else {
        insert(&(*root)->r, d);
    }
}


int maxheight(Node* root)
{
    if (root == NULL) {
        return 0;
    }
    
    return max(maxheight(root->l), maxheight(root->r)) + 1;
}

int minheight(Node* root)
{
    if (root == NULL) {
        return 0;
    }
    
    return min(minheight(root->l), minheight(root->r)) + 1;
}

bool search(Node* root, int d)
{
    if (root == NULL) {
        return false;
    }
    else if (root->d == d) {
        return true;
    }
    else if (root->d > d) {
        return search(root->l, d);
    }
    else {
        return search(root->r, d);
    }
}



int main(int argc, const char * argv[]) {

    return 0;
}
