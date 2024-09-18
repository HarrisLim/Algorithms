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
    bool hasCycle(ListNode *head) {
        int i =0;
        while(head)
        {
            if(i>10000)
                return true;
            
            head = head->next;
            i++;
        }

        return false;
    }
};
