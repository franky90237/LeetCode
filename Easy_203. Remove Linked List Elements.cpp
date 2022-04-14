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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* pre=NULL;        
        
        while(head && head->val==val)
        {
            pre=head;            
            head=head->next;
            delete pre;
        }
                
        if(!head) return NULL;
        
        ListNode* cur=head->next;
        pre=head;
        while(cur)
        {
            cout<<cur->val<<endl;
            if(cur->val==val)
            {
                ListNode* tmp=cur;
                pre->next=cur->next;
                cur=cur->next;
                delete tmp;
            }
            else
            {
                pre=cur;
                cur=cur->next;
            }      
        }
        
        return head;
    }
};
