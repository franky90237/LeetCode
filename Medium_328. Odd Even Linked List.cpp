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

//2022-08-02
//time  : O(n)
//space : O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head)
    {
        if(!head || !head->next) return head;
                
        ListNode* odd=head;    
        ListNode* even=head->next;
        ListNode* even_head=head->next;
                
        while(odd && even && even->next)
        {
            odd->next=even->next;
            even->next=even->next->next;
            
            odd=odd->next;
            even=even->next;
        }
        
        odd->next=even_head;
        return head;
    }
};

//2022-08-18
//time  : O(n)
//space : O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head)
    {
        /*
        1->2->3->4->5
        
        o : 5
        e : X
        1->3->5 2->4->X
        */
        
        if(!head || !head->next) return head;
        
        ListNode* odd=head;
        ListNode* even_head=head->next;
        ListNode* even=head->next;
        
        while(even && even->next)
        {
            odd->next=even->next;
            even->next=even->next->next;
            
            odd=odd->next;
            even=even->next;
        }
        
        odd->next=even_head;        
        
        return head;
    }
};
