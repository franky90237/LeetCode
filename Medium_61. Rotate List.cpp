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

//2022-08-27
//time  : O(n)
//space : O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {        
        if(!head || !head->next || k==0) return head;
        
        int size=0;
        ListNode* first_rear=reverse_list(head,size);
        
        k=k%size;        
        if(k==0) return reverse_list(first_rear,size);
        
        ListNode* second_head=NULL;
        ListNode* first_head=reverse_front_k_list(first_rear,second_head,k);
        first_rear->next=reverse_list(second_head,size);
        
        return first_head;
    }
    
    ListNode* reverse_list(ListNode* head, int& size)
    {
        ListNode* pre=NULL;
        ListNode* cur=head;
        
        while(cur)
        {
            ++size;
            
            ListNode* nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
        }
        
        return pre;
    }
    
    ListNode* reverse_front_k_list(ListNode* head, ListNode*& second_head, int k)
    {
        ListNode* pre=NULL;
        ListNode* cur=head;
        
        while(k>0)
        {
            second_head=cur->next;
            cur->next=pre;
            pre=cur;
            cur=second_head;
            
            --k;
        }
        
        return pre;
    }    
};

//2022-08-27
//time  : O(n)
//space : O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {        
        if(!head || !head->next || k==0) return head;
        
        int len=0;
        ListNode* tail=NULL;
        ListNode* cur=head;
        while(cur)
        {
            ++len;
            tail=cur;
            cur=cur->next;
        }
        
        k%=len;
        if(k==0) return head;
        
        ListNode* new_tail=NULL;
        ListNode* new_head=head;
        for(int i=1; i<=len-k; ++i)
        {
            new_tail=new_head;
            new_head=new_head->next;
        }
        
        tail->next=head;
        new_tail->next=NULL;
        
        return new_head;                
    }      
};
