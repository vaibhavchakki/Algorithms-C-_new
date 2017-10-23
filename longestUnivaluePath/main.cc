/* 
 * Given a binary tree, find the length of the longest path where each node in the path has the same value. 
 * This path may or may not pass through the root.
 * 
 * Note: The length of path between two nodes is represented by the number of edges between them.
 * Example 1:
 * Input:
 * 
 *               5
 *              / \
 *             4   5
 *            / \   \
 *           1   1   5
 * Output:
 * 2
 * Example 2:
 * Input:
 * 
 *               1
 *              / \
 *             4   5
 *            / \   \
 *           4   4   5
 * Output:
 * 2
 */
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int v):val(v), left(NULL), right(NULL) {}
};

int helper(TreeNode* root, int val) {
  if (NULL == root) {
    return 0;
  }
  
  if (val != root->val) {
    return 0;
  }

  return 1 + max(helper(root->left, val), helper(root->right, val));
}

int longestUnivaluePath(TreeNode* root) {
  if (NULL == root) {
    return 0;
  }

  int maxValue = max(longestUnivaluePath(root->left),
                     longestUnivaluePath(root->right));

  maxValue = max (maxValue, helper(root->left, root->val) + helper(root->right, root->val));

  return maxValue;
}

int main(int argc, const char** argv) {
  return 0;
}
