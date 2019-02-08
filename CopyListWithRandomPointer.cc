/*
https://leetcode.com/problems/copy-list-with-random-pointer
 */
 
 /**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> umap;
        
        RandomListNode* curr = head;
        
        while (curr) {
            umap[curr] = new RandomListNode(curr->label);
            curr = curr->next;
        }
        
        curr = head;
        
        while (curr) {
            umap[curr]->next = umap[curr->next];
            umap[curr]->random = umap[curr->random];
            curr = curr->next;
        }
        
        return umap[head];
    }
};
