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

//2022-06-28
//time  : O(n)
//space : O(n)
class Solution {
public:
    void reorderList(ListNode* head)
    {
        if(!head->next || !head->next->next) return;
                
        ListNode* pre=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next)
        {            
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* second=slow;
        if(!fast) slow=pre;

        //cout<<slow->val<<"-"<<second->val<<endl;
        solve(head,slow,second);
        
        /*while(head)
        {
            cout<<head->val<<" ";
            head=head->next;
        }*/
    }
    
    ListNode* solve(ListNode* head, ListNode* last, ListNode*& second)
    {
        if(head==last)
        {
            if(head==second)
            {
                second=second->next;
                last->next=NULL;
            }
            else
            {
                second=second->next;
                last->next->next=NULL;
            }
            
            return head;
        }
        
        ListNode* pre=solve(head->next,last,second);
        //cout<<pre->val<<" - "<<head->val<<" "<<second->val<<endl;
        head->next=second;
        
        ListNode* tmp=second->next;
        second->next=pre;                
        second=tmp;        
        
        return head;        
    }
};
