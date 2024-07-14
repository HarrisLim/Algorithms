/*3217. Delete Nodes From Linked List Present in Array*/
#include <iostream>
#include <vector>
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
    for(int i=0; i<nums.size(); i++)
    {
        int strIdx=0;
        // how can i loop for struct?
        // I dont know how can I next value in Pointer
        while(head->val != 0)
        {
            if(head->val == nums[i])
            {
                head->val=0;
            }
            head->val = head->next->val;
        }
    }
    return head;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    ListNode* head;
    head->val = 1;
    head->next->val = 2;
    head->next->next->val = 3;
    head->next->next->next->val = 4;
    head->next->next->next->next->val = 5;
    modifiedList(nums, head);
    
    cout << "ret: " << head->val;
    return 0;
}