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


//2022-05-04
//TLE
//quick sort
//time  : O(nlog(n))
//space : O(log(n))
class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        quick_sort(head,NULL);
        return head;
    }
    
    void quick_sort(ListNode* head, ListNode* tail)
    {
        if(head==tail || head->next==tail) return;
        //printf("%d. \n",head->val);
        
        ListNode* pivot=partition(head,tail);
        quick_sort(head,pivot);
        quick_sort(pivot->next,tail);
    }
    
    ListNode* partition(ListNode* head, ListNode* tail)
    {
        ListNode* small=head;
        ListNode* curr=head->next;
        
        while(curr!=tail)
        {
            if(curr->val<head->val)
            {
                int tmp=curr->val;
                curr->val=small->next->val;
                small->next->val=tmp;
                
                small=small->next;
            }
            
            curr=curr->next;
        }
        
        if(small->val<head->val)
        {
            int tmp=small->val;
            small->val=head->val;
            head->val=tmp;
        }
        
        //print_list(head);
        
        return small;
    }
    
    void print_list(ListNode* head)
    {
        while(head)
        {
            printf("%d ",head->val);
            head=head->next;
        }
        
        printf("\n");
    }
};

//2022-05-04
//merge sort
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    ListNode* sortList(ListNode* head)
    {        
        return merge_sort(head);
    }
    
    ListNode* merge_sort(ListNode* head)
    {
        int size=1;
        int len=get_len(head);
        
        while(size<=len)
        {
            ListNode* end=NULL;
            ListNode* pre=NULL;
            ListNode* cur=head;
            ListNode* fs=cur;
            ListNode* fe=cur;
            ListNode* ss=cur;
            ListNode* se=cur;
            
            int cnt=ceil((float)len/(2.0*size));            
            for(int i=0; i<cnt; ++i)
            {                
                pre=end;
                fs=cur;
                
                cur=split(fs,fe,ss,se,size);
                if(!ss) break;
                //printf("%d %d %d %d - %d \n",fs->val, fe->val, ss->val, se->val, cur->val);
                /*if(i==1) 
                {
                    printf("%d ",fs->val);
                    printf("%d ",fe->val);
                    printf("%d \n",ss->val);
                    //printf("%d \n",cur->val);
                }*/
                
                ListNode* start=merge(fs,fe,ss,se,cur,end);
                if(i==0) head=start;
                else if(pre) pre->next=start;
                
                //print_list(head);
            }
            
            //cout<<cnt<<endl<<endl;
            size*=2;
        }
        
        return head;
    }
    
    ListNode* split(ListNode*& fs, ListNode*& fe, ListNode*& ss, ListNode*& se, int size)
    {
        ListNode* cur=fs;
        
        for(int i=0; cur && i<size; ++i)
        {
            //fe=cur;
            cur=cur->next;
        }
        
        fe=cur;
        ss=cur;
        for(int i=0; cur && i<size; ++i)
        {
            //se=cur;
            cur=cur->next;
        }
        se=cur;
        
        return cur;
    }
    
    ListNode* merge(ListNode*& fs, ListNode*& fe, ListNode*& ss, ListNode*& se, ListNode*& last, ListNode*& end)
    {
        ListNode dummy;
        ListNode* cur=&dummy;        
        
        while(fs!=fe && ss!=se)
        {
            if(fs->val < ss->val)
            {
                cur->next=fs;
                fs=fs->next;
            }
            else
            {
                cur->next=ss;
                ss=ss->next;
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
        
        end=cur;
        cur->next=last;
        //print_list(&dummy);
        return dummy.next;
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
    
    void print_list(ListNode* head)
    {
        while(head)
        {
            cout<<head->val<<" ";
            head=head->next;
        }
        
        cout<<endl;
    }
};
