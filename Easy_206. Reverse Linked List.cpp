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

//2022-06-25
//time  : O(n)
//spcae : O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre=NULL;
        ListNode* cur=head;
        ListNode* nxt;
        
        while(cur)
        {
            nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
        }
        
        return pre;
    }
};
