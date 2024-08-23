/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int idx=0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            temp = temp->next;
            idx++;
        }
        
        for(int i=0; i<idx/2; i++)
            head = head->next;

        return head;
    }
};
