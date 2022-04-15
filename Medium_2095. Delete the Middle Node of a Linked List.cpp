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

//2022-04-14
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

//2022-04-14
//time  : O(n)
//space : O(n)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) 
    {
        vector<ListNode*> m;
        ListNode* cur=head;    
        while(cur)
        {
            m.push_back(cur);
            cur=cur->next;
        }
        
        int cnt=m.size();
        if(cnt==1) 
        {
            delete head;
            return NULL;
        }
        
        int mid=cnt/2;
        delete m[mid];
        ListNode* pre=m[mid-1];
        if(mid+1>=cnt) pre->next=NULL;
        else pre->next=m[mid+1];
                
        return head;
    }
};

//2022-04-15
//time  : O(n)
//space : O(1)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) 
    {
        if(!head->next)
        {
            delete head;
            return NULL;
        }
        if(!head->next->next)
        {
            delete head->next;
            head->next=NULL;
            return head;
        }
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
            
        ListNode* removed=slow->next;
        *slow=*(slow->next);
        delete removed;
        
        return head;
    }
};
