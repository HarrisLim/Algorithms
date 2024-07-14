/*3217. Delete Nodes From Linked List Present in Array*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* modifiedList(vector<int>& nums, ListNode* head) 
{
    unordered_set<int> numSet(nums.begin(), nums.end());
    ListNode dummy(0);
    dummy.next = head;
    ListNode* current = &dummy;

    while(current->next != nullptr)
    {
        if(numSet.find(current->next->val) != numSet.end())
        {
            // if current->next->val is in numSet, remove current->next
            current->next = current->next->next;
        }
        else
        {
            // if current->next->val is not in numSet, move next noce
            current = current->next;
        }
        cout << "ret: " << current->val;
    }

    return dummy.next;
}

/* Mine */
// ListNode* modifiedList(vector<int>& nums, ListNode* head) 
// {    
//     for(int i=0; i<nums.size(); i++)
//     {
//         int strIdx=0;
//         // how can i loop for struct?
//         // I dont know how can I next value in Pointer
//         while(head->val != 0)
//         {
//             if(head->val == nums[i])
//             {
//                 head->val=0;
//             }
//             head->val = head->next->val;
//         }
//     }
//     return head;
// }
int main()
{
    vector<int> nums = {1, 2, 3};

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    modifiedList(nums, head);
    
    return 0;
}