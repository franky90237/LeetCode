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

//2022-05-04
//TLE
//quick sort
//time  : O(nlog(n))
//space : O(log(n))
class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        quick_sort(head,NULL);
        return head;
    }
    
    void quick_sort(ListNode* head, ListNode* tail)
    {
        if(head==tail || head->next==tail) return;
        //printf("%d. \n",head->val);
        
        ListNode* pivot=partition(head,tail);
        quick_sort(head,pivot);
        quick_sort(pivot->next,tail);
    }
    
    ListNode* partition(ListNode* head, ListNode* tail)
    {
        ListNode* small=head;
        ListNode* curr=head->next;
        
        while(curr!=tail)
        {
            if(curr->val<head->val)
            {
                int tmp=curr->val;
                curr->val=small->next->val;
                small->next->val=tmp;
                
                small=small->next;
            }
            
            curr=curr->next;
        }
        
        if(small->val<head->val)
        {
            int tmp=small->val;
            small->val=head->val;
            head->val=tmp;
        }
        
        //print_list(head);
        
        return small;
    }
    
    void print_list(ListNode* head)
    {
        while(head)
        {
            printf("%d ",head->val);
            head=head->next;
        }
        
        printf("\n");
    }
};

//2022-05-04
//merge sort
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        merge_sort(head);
        return head;
    }
    
    void merge_sort(ListNode* head)
    {
        int size=1;
        ListNode* cur=head;
        
        while(cur)
        {
            ListNode *pre=NULL;
            ListNode * end=cur;
            for(int i=0; i<cnt; ++i) end=end->next;
        }
    }
    
    void merge(ListNode* first, ListNode* second, int cnt)
    {
        ListNode dummy;
        ListNode *cur=&dummy;
        
        for(int i=0; i<cnt; ++i)
        {
            if(first->val < second->val)
            {
                cur->next=first;
                first=first->next;
            }
            else
            {
                cur->next=second;
                second=second->next;                
            }
        }
    }
    
    void print_list(ListNode* head)
    {
        while(head)
        {
            printf("%d ",head->val);
            head=head->next;
        }
        
        printf("\n");
    }
};
