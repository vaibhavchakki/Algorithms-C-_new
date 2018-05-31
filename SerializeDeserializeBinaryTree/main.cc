/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
	 Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

	Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

	Example: 

	You may serialize the following tree:

		1
	   / \
	  2   3
		 / \
		4   5

	as "[1,2,3,null,null,4,5]"
	Clarification: Just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

	Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
	
	https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 */
 
 
class Codec {
public:
    
    void buildString(TreeNode* root, stringstream& ss) {
        if (root == NULL) {
            ss << "X" << " ";
        }
        else {
            ss << root->val << " ";
            buildString(root->left, ss);
            buildString(root->right, ss);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;        
        buildString(root, ss);
        //cout << ss.str() << endl;
        return ss.str();
    }
    
    TreeNode* buildTree(stringstream& ss) {
        string s;
        ss >> s;
        
        if (s == "X") {
            return NULL;
        }
        else {
            //cout << s << endl;
            TreeNode* root = new TreeNode(stoi(s));
            root->left = buildTree(ss);
            root->right = buildTree(ss);
            return root;
        }
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        //cout << data << endl;
        
        return buildTree(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));