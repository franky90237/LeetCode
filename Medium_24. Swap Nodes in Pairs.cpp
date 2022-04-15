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
//recursive
class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(!head || !head->next) return head;
        return swapPairs(NULL,head);
    }
    
    ListNode* swapPairs(ListNode* pre, ListNode* head) 
    {
        if(!head || !head->next) return head;
        
        ListNode* first=head->next;
        ListNode* second=head->next->next;
        if(pre) pre->next=first;
        first->next=head;
        head->next=second;
        
        swapPairs(head,second);
        
        return first;
    }
};
