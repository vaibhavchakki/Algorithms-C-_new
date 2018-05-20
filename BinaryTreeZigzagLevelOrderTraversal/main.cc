/**
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *   3
 *  / \
 * 9  20
 *   /  \
 *  15   7
 * return its zigzag level order traversal as:
 * [
 *  [3],
 *  [20,9],
 *  [15,7]
 * ]
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
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
    
    void helper(int level, TreeNode* root, vector<deque<int>>& result) {
        if (root == NULL) {
            return;
        }
        
        if (result.size() == level) {
            result.push_back(deque<int>());
        }
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        if (level % 2) {
            result[level].push_front(root->val);
        }
        else {
            result[level].push_back(root->val);
        }
        
        helper(level + 1, left, result);
        helper(level + 1, right, result);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<deque<int>> tmp;
        
        if (root == NULL) {
            return {};
        }
        
        helper(0, root, tmp);
        
        vector<vector<int>> result;
        
        for (auto& l : tmp) {
            vector<int> t;
            for (auto& e: l) {
                t.push_back(e);
            }
            result.push_back(t);
        }
        
        return result;
    }
};