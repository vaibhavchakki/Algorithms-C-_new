#include <iostream>
#include <memory>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

class BinaryTreeNode
{
public:
    int value_;
    BinaryTreeNode* left_;
    BinaryTreeNode* right_;

    BinaryTreeNode(int value) :
        value_(value),
        left_(nullptr),
        right_(nullptr)
    {
    }

    ~BinaryTreeNode()
    {
        delete left_;
        delete right_;
    }

    BinaryTreeNode* insertLeft(int value)
    {
        this->left_ = new BinaryTreeNode(value);
        return this->left_;
    }

    BinaryTreeNode* insertRight(int value)
    {
        this->right_ = new BinaryTreeNode(value);
        return this->right_;
    }
};

bool isValid(const BinaryTreeNode* root, int _min, int _max) {
    if (root == NULL) {
        return true;
    }
    
    if ((root->value_ < _min) || (root->value_ > _max)) {
        return false;
    }
    
    return isValid(root->left_, _min, root->value_) && isValid(root->right_, root->value_, _max);

}

bool isBinarySearchTree(const BinaryTreeNode* root)
{
    // determine if the tree is a valid binary search tree
    
    return isValid(root, INT_MIN, INT_MAX);
}