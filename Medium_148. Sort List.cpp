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
class Solution {
public:
    ListNode* sortList(ListNode* head)
    {
        merge_sort(head);
        return head;
    }
    
    void merge_sort(ListNode* head)
    {
        int size=1;
        int len=get_len(head);
        
        while(size<=len)
        {
            ListNode* cur=head;
            ListNode* fs=cur;
            ListNode* fe=cur
            ListNode* ss=cur;
            ListNode* ss=cur;
            
            int cnt=ceil(len/(2.0*size));
            for(int i=0; i<cnt; ++i)
            {
                fs=cur;
                
                cur=spilt(*fs,*fe,*ss,*se,size);
                ListNode* last=merge(*fs,*fe,*ss,*se,size);
                
                last->next=cur;
            }
            
            size*=2;
        }
    }
    
    ListNode* split(ListNode** fs, ListNode** fe, ListNode** ss, ListNode** se, int size)
    {
        ListNode* cur=fs;
        
        for(int i=0; i<size; ++i)
        {
            //**fe=&cur;
            cur=cur->next;
        }
        
        **fe=&cur;
        **ss=&cur;
        for(int i=0; cur && i<size; ++i)
        {
            //se=cur;
            cur=cur->next;
        }
        **se=&cur;
        
        return cur;
    }
    
    ListNode* merge(ListNode* fs, ListNode* fe, ListNode* ss, ListNode* se, int size)
    {
        ListNode dummy;
        ListNode* cur=&dummy;
        //int cf=0, cs=0;
        
        while(fs!=fe && st!=se)
        {
            if(fs->val < ss->val)
            {
                cur->next=fs;
                fs=fs->next;
                //++cf;
            }
            else
            {
                cur->next=ss;
                ss=ss->next;
                //++cs;
            }
            
            cur=cur->next;
        }
        
        while(fs!=fe)
        {
            cur->next=fs;
            fs=fs->next;
            cur=cur->next;
        }
        
        while(ss!=se)
        {
            cur->next=ss;
            ss=ss->next;
            cur=cur->next;
        }
        
        return cur;
    }
    
    int get_len(ListNode* head)
    {
        int len=0;
        while(head)
        {
            ++len;
            head=head->next;
        }
        
        return len;
    }
};
