/*
 * Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
 * Example 1:
 * Input:
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * Output: [3, 14.5, 11]
 * Explanation:
 * The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* root) {
  if (NULL == root) {
    return 0;
  }

  return 1 + max(height(root->left), height(root->right));
}


vector<double> averageOfLevels(TreeNode* root) {
  // first get height of tree
  int h = height(root);

  // declare result with size as h, and initialize with 0
  vector<double> result(h, 0);

  // declare nodes an array to store the nodes at same level
  vector<TreeNode*> nodes;
   
  // if root is null return 0 
  if (NULL == root) {
    return result;
  }

  // start at level 0
  int level = 0;
  // push it in the nodes
  nodes.push_back(root);

  // if we are below the height process
  while (level < h) {
    // declare a temp node
    vector<TreeNode*> temp;

    // iterate all nodes at same level and store the sum in result[level]
    // also store the next level nodes in temp array    
    for (int i = 0; i < nodes.size(); i++) {
      result[level] += nodes[i]->val;
        
      if (nodes[i]->left) {
        temp.push_back(nodes[i]->left);
      }
        
      if (nodes[i]->right) {
        temp.push_back(nodes[i]->right);
      }
    }
    // calculate avg
    result[level] = result[level] / nodes.size();

    // increment to next level
    level = level + 1;
    // copy temp back to nodes
    nodes = temp;
  }

  return result;
}


// solution 2 without using height function
vector<double> averageOfLevels2(TreeNode* root) {
  vector<double> result;
  vector<TreeNode*> nodes;
    
  if (NULL == root) {
    return result;
  }
    
  int level = 0;
  nodes.push_back(root);
    
  while (nodes.size() != 0) {
    double avgSum = 0;
    vector<TreeNode*> temp;
        
    for (int i = 0; i < nodes.size(); i++) {
      avgSum += nodes[i]->val;
            
      if (nodes[i]->left) {
        temp.push_back(nodes[i]->left);
      }
            
      if (nodes[i]->right) {
        temp.push_back(nodes[i]->right);
      }
    }
    avgSum = avgSum / nodes.size();
    level = level + 1;
    nodes = temp;
    result.push_back(avgSum);
  }
    
  return result;
}

int main(int argc, const char** argv) {
  return 0;
}
