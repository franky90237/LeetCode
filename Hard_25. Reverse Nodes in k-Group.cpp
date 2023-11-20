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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        /*
        d 1->2->3->4->5
          ^     ^        
        pre  = 1
        cur  = 3
        tail = X
        next = X
        
        1<-2<-d
        */
        if(!head || !head->next || k==1) return head;
        
        int len=list_len(head);
        
        //ListNode* new_head=NULL;
        ListNode dummy;
        ListNode* pre=&dummy;    
        ListNode* cur=head;
        
        int cnt=len/k;
        for(int i=1; i<=cnt; ++i)
        {
            ListNode* next_cur=NULL;
            ListNode* tail=reverse_list(cur,next_cur,k);
            if(!dummy.next) dummy.next=tail;
            
            pre->next=tail;
            pre=cur;
            cur=next_cur;            
        }
        
        if(cur) pre->next=cur;
        
        return dummy.next;
    }
    
    int list_len(ListNode* head)
    {
        int len=0;
        while(head)
        {
            ++len;
            head=head->next;
        }
        
        return len;
    }
    
    ListNode* reverse_list(ListNode* head, ListNode*& next_head, int k)
    {
        ListNode* pre=NULL;
        ListNode* cur=head;
        
        while(k>0)
        {
            next_head=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next_head;
            
            --k;
        }
        
        return pre;
    }
};

//2023-11-20
//time  : O(n)
//space : O(1)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        int len=0;
        ListNode* cur=head;
        while(cur)
        {
            cur=cur->next;
            ++len;
        }
        
        ListNode dummy;
        dummy.next=head;
        ListNode* pre=&dummy;
        cur=head;
        for(int i=0; i<len/k; ++i)
        {
            ListNode* tail = reverseList(cur, k);
            pre->next=tail;
            pre=cur;
            cur=cur->next;
        }
        
        return dummy.next;
    }
    
    ListNode* reverseList(ListNode* head, int k)
    {
        ListNode* pre=NULL;
        ListNode* cur=head;
        for(int cnt=0; cnt<k; ++cnt)
        {
            ListNode* nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
        }
        
        head->next=cur;        
        return pre;
    }
};
