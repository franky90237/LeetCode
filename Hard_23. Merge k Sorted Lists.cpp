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

//2022-07-14
//time  : O(n*m), m is the average size of each list
//space : O(n)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        int n=lists.size();
        if(n==0) return NULL;
                
        ListNode* ptr[n];
        for(int i=0; i<n; ++i) ptr[i]=lists[i];
        
        ListNode* dummy=new ListNode();
        ListNode* cur=dummy;
        while(true)
        {
            ListNode* min_node=find_min(lists);
            if(!min_node) break;
            
            //cout<<min_node->val<<endl;
            cur->next=min_node;
            cur=cur->next;
        }
        
        return dummy->next;
    }
    
    ListNode* find_min(vector<ListNode*>& lists)
    {
        int min_val=INT_MAX;
        ListNode* min_node=NULL;
        ListNode** tmp=NULL;
        for(auto& node:lists)
        {
            //cout<<node->val<<endl;
            if(node && node->val < min_val)
            {
                min_val=node->val;
                min_node=node;
                tmp=&node;
            }
        }
        
        if(min_node) *tmp=(*tmp)->next;
        return min_node;
    }
};

//2022-07-14
//min heap
//time  : O(n*m), m is the average size of each list
//space : O(n)
class Solution {
private:
    class comp
    {
    public:
        bool operator()(const ListNode* a, const ListNode* b)
        {
            return a->val > b->val;
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        int n=lists.size();
        if(n==0) return NULL;
                
        priority_queue<ListNode*,vector<ListNode*>,comp> min_heap;
        for(auto& node:lists)
        {
            while(node)
            {
                min_heap.push(node);
                node=node->next;
            }
        }
        
        ListNode dummy;        
        ListNode* cur=&dummy;
        while(!min_heap.empty())
        {
            //cout<<min_heap.top()->val<<endl;
            cur->next=min_heap.top();
            min_heap.pop();
            cur=cur->next;
        }
        
        cur->next=NULL;
        return dummy.next;
    }
};
