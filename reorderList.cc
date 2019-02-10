/*
  https://leetcode.com/problems/reorder-list
 */
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> l;
        
        while (head) {
            l.push_back(head); head = head->next;
        }
        
        for (int start = 0, end = l.size() - 1;start <= end; start++, end--) {
            l[start]->next = l[end];
            l[end]->next = (start + 1) <= (end - 1) ? l[start+1] : nullptr;
        }
        
    }
};
