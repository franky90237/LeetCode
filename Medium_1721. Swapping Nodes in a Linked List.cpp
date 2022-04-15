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
 
 //2022-04-15
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* cur=head;        
        for(int i=1; i<k; ++i)
        {
            cur=cur->next;
        }        
        ListNode* forward=cur;
        
        ListNode* backward=head;
        while(cur->next)
        {
            backward=backward->next;
            cur=cur->next;
        }
        
        int tmp=forward->val;
        forward->val=backward->val;
        backward->val=tmp;
        
        return head;
    }
};
