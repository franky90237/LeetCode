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

//2022-06-25
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* cur=head;
        
        int i=1;
        while(i!=n+1)
        {
            cur=cur->next;
            ++i;
        }
        
        /*if(!cur) 
        {
            delete head;
            return NULL;
        }*/
        
        ListNode* pre=NULL;
        ListNode* removed=head;
        while(cur)
        {
            pre=removed;
            removed=removed->next;
            cur=cur->next;
        }
        
        if(pre)
        {
            pre->next=removed->next;
        }
        else if(removed==head)
        {
            head=head->next;
        }
        
        delete removed;
        return head;
    }
};

//2022-08-02
//time  : O(n)
//space : O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {        
        ListNode* cur=head;
        for(int i=1; i<=n; ++i) cur=cur->next;
        
        ListNode* pre=NULL;
        ListNode* removed=head;
        
        while(cur)
        {
            pre=removed;
            removed=removed->next;
            cur=cur->next;
        }
        
        if(!pre) head=head->next;
        else pre->next=removed->next;
        
        delete removed;        
        return head;
    }
};

//2022-09-28
//time  : O(n)
//space : O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        /*
        n=2
        1 2 3 4 5

        (1,3) (2,4) (3,5) (4,NULL)

        */
        
        ListNode* cur=head;
        for(int i=0; i<n; ++i)
        {
            cur=cur->next;
        }
        
        ListNode* pre=NULL;
        ListNode* to_be_deleted=head;
        while(cur)
        {
            pre=to_be_deleted;
            to_be_deleted=to_be_deleted->next;
            cur=cur->next;
        }
        
        if(pre) pre->next=to_be_deleted->next;
        else head=to_be_deleted->next;
        
        delete to_be_deleted;
        return head;
    }
};
