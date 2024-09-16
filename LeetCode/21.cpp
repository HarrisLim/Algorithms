class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergedList = nullptr;
        ListNode* ReList1 = new ListNode(-999);
        ListNode* ReList2 = new ListNode(-999);
        
        while(list1 != nullptr)
        {
            ListNode* temp = list1->next;
            list1->next = ReList1;
            ReList1 = list1;
            list1 = temp;
        }
        while(list2 != nullptr)
        {
            ListNode* temp = list2->next;
            list2->next = ReList2;
            ReList2 = list2;
            list2 = temp;
        }

        while(ReList1->val != -999 || ReList2->val !=-999)
        {
            if(ReList1->val > ReList2->val)
            {
                ListNode* temp = ReList1->next;
                ReList1->next = mergedList;
                mergedList = ReList1;
                ReList1 = temp;
            }
            else
            {
                ListNode* temp = ReList2->next;
                ReList2->next = mergedList;
                mergedList = ReList2;
                ReList2 = temp;
            }
        }

        return mergedList;
    }
};
