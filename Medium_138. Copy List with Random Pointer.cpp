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

//2022-09-07
//time  : O(n)
//space : O(1)
class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        /*
        a->b->c->d
        A->B->C->D
        
        a->A->b->B->c->C->d->D
        
        A->random=a->random->next
        */                
        
        /*
        a->b
        
        A->b
        a->A->b
        */        
        Node* copy_head=NULL;
            
        Node* old=head;
        while(old)
        {
            Node* copy_node=new Node(old->val);
            if(!copy_head)  copy_head=copy_node;
            
            copy_node->next=old->next;
            old->next=copy_node;
            old=copy_node->next;
        }
        
        Node* copy=copy_head;
        old=head;
        while(old)
        {
            if(old->random) 
            {                
                copy->random=old->random->next;                
            }
            
            if(copy->next) copy=copy->next->next;
            old=old->next->next;
        }
        
        /*
        a->A->b->B->X
              ^  ^
              o  c
        
        a->b
        A->B
        */
        copy=copy_head;
        old=head;
        while(old)
        {
            old->next=old->next->next;
            old=old->next;
            
            if(copy->next) 
            {
                copy->next=copy->next->next;
                copy=copy->next;
            }
        }
        
        return copy_head;
    }
};
