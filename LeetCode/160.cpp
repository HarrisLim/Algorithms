/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// ## using map
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mp;

        ListNode* tempA = headA;
        while(tempA)
        {
            mp[tempA]++;
            tempA = tempA->next;
        }

        ListNode* tempB = headB;
        while(tempB)
        {
            if(mp.find(tempB) != mp.end())
                return tempB;
            tempB = tempB->next;
        }
        return nullptr;
    }
};

/*
// ## Two pointers technique
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ret = nullptr;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int lengA=0, lengB=0;
        while(tempA)
        {
            lengA++; tempA = tempA->next;
        }
        while(tempB)
        {
            lengB++; tempB = tempB->next;
        }
        
        int max_len = max(lengA, lengB);
        for(int i=0; i<max_len; i++)
        {
            if(lengA > lengB)
            {
                lengA--;
                headA = headA->next;
            }
            else if(lengA < lengB)
            {
                lengB--;
                headB = headB->next;
            }
            // if same positioin
            else
            {
                if(headA != headB)
                {
                    headA = headA->next;
                    headB = headB->next;
                }
                else
                {
                    ret = headA;
                    break;
                }
            }
        }

        return ret;
    }
};
*/
