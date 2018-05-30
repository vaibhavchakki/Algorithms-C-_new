/**

	Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.

	Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

	The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.

	The right-most node is also defined by the same way with left and right exchanged.

	Example 1
	Input:
	  1
	   \
		2
	   / \
	  3   4

	Ouput:
	[1, 3, 4, 2]

	Explanation:
	The root doesn't have left subtree, so the root itself is left boundary.
	The leaves are node 3 and 4.
	The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
	So order them in anti-clockwise without duplicates and we have [1,3,4,2].
	Example 2
	Input:
		____1_____
	   /          \
	  2            3
	 / \          / 
	4   5        6   
	   / \      / \
	  7   8    9  10  
		   
	Ouput:
	[1,2,4,7,8,9,10,6,3]

	Explanation:
	The left boundary are node 1,2,4. (4 is the left-most node according to definition)
	The leaves are node 4,7,8,9,10.
	The right boundary are node 1,3,6,10. (10 is the right-most node).
	So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].
	
	https://leetcode.com/problems/boundary-of-binary-tree/description/

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
    
    void left(TreeNode* node, vector<int>& r) {
        if ((node == NULL) || ((node->left == NULL) && (node->right == NULL))) {
            return;
        }
        
        r.push_back(node->val);
        
        if (node->left) { 
            left(node->left, r); 
        }
        else if (node->right) {
            left(node->right, r);
        }
    }
    
    void right(TreeNode* node, vector<int>& r) {
        if ((node == NULL) || ((node->left == NULL) && (node->right == NULL))){
            return;
        }
        if (node->right) {
            right(node->right, r);
        }
        else {
            right(node->left, r);
        }
        r.push_back(node->val);
    }
            
    void leaves(TreeNode* node, vector<int>& r) {
        if (node == NULL) {
            return;
        }
        
        if ((node->left == NULL) && (node->right == NULL)) {
            r.push_back(node->val);
            return;
        }
        leaves(node->left, r);
        leaves(node->right, r);
    }
    
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> r;
        
        if (root == NULL) {
            return r;
        }
        
        r.push_back(root->val);
        
        left(root->left, r);
        leaves(root->left, r);
        leaves(root->right, r);
        right(root->right, r);
        
        return r;
    }
};