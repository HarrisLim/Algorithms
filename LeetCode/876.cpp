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
        while(temp->next != NULL)
        {
            temp = temp->next;
            idx++;
        }
        
        int n = idx % 2 == 0 ? idx/2 : idx/2+1;
        for(int i=0; i<n; i++)
            head = head->next;

        return head;
    }
};
