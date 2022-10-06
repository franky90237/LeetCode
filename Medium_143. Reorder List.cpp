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

//2022-08-12
//time  : O(n)
//space : O(1)
class Solution {
public:
    void reorderList(ListNode* head)
    {
        if(!head || !head->next) return;
        
        ListNode* slow=head;
        ListNode* fast=head;
                
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* last = revere_linked_list(slow);
        ListNode* cur=head;
        
        while(cur!=last && last->next)
        {
            ListNode* nxt_cur=cur->next;
            ListNode* nxt_last=last->next;
            
            cur->next=last;
            last->next=nxt_cur;
            
            cur=nxt_cur;
            last=nxt_last;
        }        
    }
    
    ListNode* revere_linked_list(ListNode* head)
    {
        ListNode* pre=NULL;
        ListNode* cur=head;
        
        while(cur)
        {
            ListNode* nxt=cur->next;            
            cur->next=pre;
            pre=cur;
            cur=nxt;
        }
        
        return pre;
    }
};

//2022-10-07
//time  : O(n*n)
//space : O(n)
class Solution {
public:
    void reorderList(ListNode* head) 
    {        
        if(!head) return;
        
        ListNode* last=get_last(head);
        if(!last || last == head) return;
        
        ListNode* tmp=head->next;
        head->next=last;
        last->next=tmp;
        
        reorderList(tmp);
    }
    
    ListNode* get_last(ListNode* head)
    {
        if(!head) return NULL;
        
        ListNode* pre=NULL;
        ListNode* cur=head;
        while(cur->next)
        {
            pre=cur;
            cur=cur->next;
        }
        
        if(pre) pre->next=NULL;
        return cur;
    }
};
