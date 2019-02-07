//https://leetcode.com/problems/validate-binary-search-tree/

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
    
    bool isValid(TreeNode* n) {
        if (n == NULL) {
            return true;
        }
        
        TreeNode* l = n->left;
        TreeNode* r = n->right;
        
        if (l && (l->val >= n->val)) {
            return false;
        }
        
        if (r && (n->val >= r->val)) {
            return false;
        }
        
        return isValid(l) && isValid(r);
    }
    
    bool isValidBST(TreeNode* root) {
        
        return isValid(root);
        
    }
};
