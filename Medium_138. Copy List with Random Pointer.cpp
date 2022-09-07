/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

//2022-09-07
//time  : O(n)
//space : O(1)
class Solution {
public:
    Node* copyRandomList(Node* head)
    {        
        unordered_map<Node*,int> record_original;
        vector<Node*> record_copy;
        
        Node dummy(0);
        Node* copy=&dummy;
        
        int i=0;
        Node* cur=head;
        while(cur)
        {
            copy->next=new Node(cur->val);            
            copy=copy->next;
            
            record_copy.push_back(copy);            
            record_original[cur]=i;
                        
            cur=cur->next;            
            ++i;
        }
        
        copy=dummy.next;
        cur=head;
        while(copy)
        {
            if(cur->random) 
            {
                int idx=record_original[cur->random];
                copy->random=record_copy[idx];                
            }
            
            copy=copy->next;
            cur=cur->next;
        }
        
        return dummy.next;
    }
};
