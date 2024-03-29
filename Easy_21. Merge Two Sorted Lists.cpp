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

//2022-07-21
//time  : O(n)
//space : O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode dummy;
        ListNode* cur=&dummy;
        
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                cur->next=list1;
                list1=list1->next;
            }
            else
            {
                cur->next=list2;
                list2=list2->next;                
            }
            
            cur=cur->next;
        }
        
        if(list1) cur->next=list1;
        else if(list2) cur->next=list2;
        
        return dummy.next;
    }
};

//2022-08-04
//dummy node
//time  : O(n)
//space : O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        /*
        1->5
        3->6
        
        cur   : -1 -> 1 -> 3 -> 5
        list1 : X
        list2 : 6
        */
        
        if(!list1) return list2;
        if(!list2) return list1;
        
        ListNode dummy(-1);
        ListNode* cur=&dummy;
        
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                cur->next=list1;
                list1=list1->next;
            }
            else
            {
                cur->next=list2;
                list2=list2->next;                
            }
            
            cur=cur->next;
        }
        
        if(list1) cur->next=list1;
        else if(list2) cur->next=list2;
        
        return dummy.next;
    }
};

//2022-08-04
//recursive
//time  : O(n)
//space : O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        /*
        1->5
        3->6
        
        stack : 1 3 5
        1 -> m(5,3) => 
        3 -> m(5,6) =>
        5 -> m(X,6) =>
        
        5 -> 6
        3- > 5 -> 6
        1 -> 3 -> 5 -> 6
        */
        
        if(!list1) return list2;
        if(!list2) return list1;
        
        if(list1->val < list2->val)
        {            
            list1->next=mergeTwoLists(list1->next,list2);
            return list1;
        }
        else
        {
            list2->next=mergeTwoLists(list1,list2->next);
            return list2;
        }
    }
};
