//2023-11-20
//time  : O(n)
//spcae : O(n)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int len1=getLen(l1);
        int len2=getLen(l2);
        if(len1 < len2) 
        {
            swap(len1, len2);
            swap(l1, l2);
        }
        
        int res = add(l1, l2, len1, len2);
        if(res == 1) 
        {
            ListNode* newHead=new ListNode(1, l1);
            l1=newHead;
        }
        return l1;
    }
    
    int getLen(ListNode* head)
    {
        int len=0;
        while(head)
        {
            head=head->next;
            ++len;
        }
        
        return len;
    }
    
    int add(ListNode* l1, ListNode* l2, int len1, int len2)
    {
        if(len1 == 0)
        {
            return 0;
        }
        
        int res=l1->val;
        if(len1 != len2)
        {
            res += add(l1->next, l2, len1-1, len2);                        
        }
        else
        {
            res += add(l1->next, l2->next, len1-1, len2-1);
            res += l2->val;
        }
        
        l1->val=res%10;
        return res/10;
    }
};
