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
    bool isPalindrome(ListNode* head) 
    {
        vector<int> *source=preprocess(head);
        
        int n=source->size();
        for(int i=0; i<n/2; ++i)
        {
            //cout<<(*source)[i]<<" "<<(*source)[n-i-1]<<endl;
            if((*source)[i]!=(*source)[n-i-1]) return false;
        }
        
        return true;
    }
    
    vector<int> * preprocess(ListNode* head)
    {
        vector<int> *source=new vector<int>();
        
        while(head!=NULL) 
        {
            //cout<<head->val<<" ";
            source->push_back(head->val);
            head=head->next;
        }
        
        return source;
    }
};

//time  : O(n)
//space : O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        ListNode* prev=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast && fast->next)
        {            
            fast=fast->next->next;
            
            ListNode* next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
        }
        
        if(fast) slow=slow->next;
        
        while(slow && prev->val==slow->val)
        {
            prev=prev->next;
            slow=slow->next;
        }
        
        return !prev;
    }

};
