/*
https://leetcode.com/problems/range-sum-of-bst/

Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.
 */
 
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void sumBST(TreeNode* root, int L, int R, int& sum) {
        if (root == NULL) {
            return;
        }
        
        if ((root->val >= L) && (root->val <= R)) {
            sum += root->val;
        }
        if (root->val >= L) { 
            sumBST(root->left, L, R, sum);
        }
        
        if (root->val <= R) {
            sumBST(root->right, L, R, sum);
        }
        
    }
    
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        
        sumBST(root, L, R, sum);
        
        return sum;
        
    }
};
