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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* slow=head;
        ListNode* fast=head;
        
        int mid=1;
        int cnt=1;
        while(fast && fast->next)
        {
            slow=slow->next;
            ++mid;
            
            fast=fast->next;
            ++cnt;
            
            if(!fast->next) break;
            fast=fast->next;
            ++cnt;
        }
        
        //cout<<n<<" "<<cnt<<endl;
        n=cnt-n+1;
        //cout<<n<<" "<<cnt<<endl;
        
        if(n==mid) return delete_node(head,slow);
        else if(n==cnt) return delete_node(head,fast);
        else if(n==1) return delete_node(head,head);
        
        if(n>mid)
        {
            for(int i=mid; i<n; ++i) slow=slow->next;
        }
        else
        {
            slow=head;
            for(int i=1; i<n; ++i) slow=slow->next;
        }
        
        return delete_node(head,slow);
    }
    
    ListNode* delete_node(ListNode* head, ListNode* removed)
    {
        if(removed==head)
        {
            head=head->next;
            delete removed;
        }
        else
        {
            if(!removed->next)
            {
                ListNode* pre=head;
                while(pre->next!=removed) pre=pre->next;
                pre->next=removed->next;
                delete removed;
            }
            else
            {
                ListNode* tmp=removed->next;
                *removed=*(removed->next);
                delete tmp;
            }
        }
        
        return head;
    }
};

//2022-04-15
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* slow=head;
        ListNode* fast=head;
        
        for(int cnt=1; cnt<n; ++cnt)
        {
            fast=fast->next;
        }
                
        ListNode* pre=NULL;
        while(fast->next)
        {
            pre=slow;
            slow=slow->next;
            fast=fast->next;
        }
        
        if(slow==head)
        {
            head=head->next;
            delete slow;
        }
        else
        {
            pre->next=slow->next;
            delete slow;
        }
        
        return head;
    }
};
