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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* cur1=l1;
        ListNode* cur2=l2;
        
        ListNode dummy;
        ListNode* pre=&dummy;
        
        int carry=0;
        while(cur1 && cur2)
        {
            int val1=cur1->val;
            int val2=cur2->val;
            
            int sum=val1+val2+carry;
            carry=sum/10;
            sum=sum%10;
            
            ListNode* node=new ListNode(sum);
            pre->next=node;
            
            pre=node;
            cur1=cur1->next;
            cur2=cur2->next;
        }
        
        while(cur1)
        {
            int sum=cur1->val+carry;
            carry=sum/10;
            sum=sum%10;
            
            ListNode* node=new ListNode(sum);
            pre->next=node;
            
            pre=node;
            cur1=cur1->next;            
        }
        
        while(cur2)
        {
            int sum=cur2->val+carry;
            carry=sum/10;
            sum=sum%10;
            
            ListNode* node=new ListNode(sum);
            pre->next=node;
            
            pre=node;
            cur2=cur2->next;            
        }
        
        if(carry!=0)
        {
            ListNode* node=new ListNode(carry);
            pre->next=node;
        }
        
        return dummy.next;
    }
};
