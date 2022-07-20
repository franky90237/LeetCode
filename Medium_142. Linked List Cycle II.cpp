/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//2022-07-20
//time  : O(n)
//space : O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast) return cycle_begin(head,fast);
        }
        
        return NULL;            
    }
    
    ListNode* cycle_begin(ListNode *head, ListNode *fast)
    {
        while(head!=fast)
        {
            //cout<<head->val<<" : "<<fast->val<<endl;
            head=head->next;
            fast=fast->next;
        }
        
        return head;
    }
};

//2022-07-20
//hash set
//time  : O(n)
//space : O(n)
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode*> table;
        ListNode* cur=head;
        
        while(cur)
        {
            if(table.count(cur)) return cur;
            
            table.insert(cur);
            cur=cur->next;
        }
        
        return NULL;            
    }    
};

//2022-07-20
//change val of node
//time  : O(n)
//space : O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode* cur=head;
        
        while(cur)
        {
            if(cur->val==INT_MAX) return cur;
            
            cur->val=INT_MAX;
            cur=cur->next;
        }
        
        return NULL;            
    }    
};
