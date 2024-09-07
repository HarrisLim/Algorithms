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
    void deleteNode(ListNode* node) {
        // how can i get previous node? by double pointer? 
        // I dont need to know about previous node. 
        node->val = node->next->val;
        node->next = node->next->next;
        
    }
};
