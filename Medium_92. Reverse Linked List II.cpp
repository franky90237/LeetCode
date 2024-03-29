//2023-11-19
//time  : O(n)
//space : O(n)
class Solution 
{
private:
    ListNode* last;
    
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        last = NULL;
        ListNode* res = reverseBetween(NULL, head, left, right);
        if(left == 1)
        {
            head->next=last;
            head=res;
        }
        
        return head;        
    }
    
    ListNode* reverseBetween(ListNode* pre, ListNode* head, int left, int right)
    {
        if(right == 0)
        {
            last=head;
            return pre;
        }
                
        if(left < 1)
        {
            ListNode* nxt = head->next;
            head->next = pre;
            return reverseBetween(head, nxt, left-1, right-1);
        }
                
        ListNode* res = reverseBetween(head, head->next, left-1, right-1);
        //cout<<res->val<<endl;
        if(left == 2)
        {          
            head->next->next=last;
            head->next = res;                        
        }
        
        return res;
    }
};

//2023-11-20
//time  : O(n)
//space : O(1)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode dummy;
        dummy.next=head;
        
        ListNode* pre=&dummy;
        ListNode* cur=head;
        int idx=1;
        while(idx < left)
        {
            pre=cur;
            cur=cur->next;
            ++idx;
        }
        
        ListNode* beforeLeft=pre;        
        while(idx <= right)
        {
            ListNode* nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
            
            ++idx;
        }
        
        beforeLeft->next->next=cur;
        beforeLeft->next=pre;
        return dummy.next;
    }
};
