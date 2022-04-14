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

//time  : O(n)
//space : O(n)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) 
    {
        unordered_map<int,ListNode*> m;
        ListNode* cur=head;
        int i=0;
        while(cur)
        {
            m[i]=cur;
            cur=cur->next;
            ++i;
        }
        
        if(i==1) 
        {
            delete head;
            return NULL;
        }
        
        int mid=i/2;
        delete m[mid];
        ListNode* pre=m[mid-1];
        pre->next=m[mid+1];
        
        return head;
    }
};
