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
    ListNode* sortList(ListNode* head) 
    {
        quick_sort(head,NULL);
        return head;
    }
    
    void quick_sort(ListNode* head, ListNode* tail)
    {
        if(head->next==tail) return;
        printf("%d. \n",head->val);
        ListNode* pivot=partition(head,tail);
        quick_sort(head,pivot);
        quick_sort(pivot->next,tail);
    }
    
    ListNode* partition(ListNode* head, ListNode* tail)
    {
        ListNode* small=head->next;
        ListNode* curr=head->next;
        
        while(curr!=tail)
        {
            if(curr->val<head->val)
            {
                int tmp=curr->val;
                curr->val=small->val;
                small->val=tmp;
                
                small=small->next;
            }
            
            curr=curr->next;
        }
        
        if(small && small->val<head->val)
        {
            int tmp=small->val;
            small->val=head->val;
            head->val=tmp;
        }
        
        return small;
    }
};
