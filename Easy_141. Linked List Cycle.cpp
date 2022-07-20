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
    bool hasCycle(ListNode *head) 
    {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast) return true;
        }
        
        return false;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//2022-07-20
//check every move
//time  : O(n)
//space : O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast && fast->next)
        {
            fast=fast->next;
            if(slow==fast) return true;
            
            fast=fast->next;
            slow=slow->next;
            if(slow==fast) return true;
        }
        
        return false;
    }
};
