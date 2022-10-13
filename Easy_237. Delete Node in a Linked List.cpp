/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//2022-04-14
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        ListNode* pre=NULL;
        ListNode* cur=node;
        
        while(cur->next)
        {
            cur->val=cur->next->val;
            
            pre=cur;
            cur=cur->next;
        }
        
        pre->next=NULL;                        
    }
};

//2022-04-14
class Solution {
public:
    void deleteNode(ListNode* node) 
    {        
        ListNode* next_node=node->next;
        *node=*next_node;
        delete next_node;
    }
};

//2022-10-13
//time  : O(1)
//space : O(1)
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        ListNode* to_be_removed=node->next;
        *node=*(node->next);
        delete to_be_removed;
    }
};
