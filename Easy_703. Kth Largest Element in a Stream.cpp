//array
class KthLargest 
{
private:
    vector<int> arr;
    int k;
    
public:
    KthLargest(int k, vector<int>& nums) 
    {
        arr=nums;
        //sort(arr.begin(),arr.end(),greater<int>());
        sort(arr.begin(),arr.end());
        this->k=k;
    }
    
    int add(int val) 
    {
        int l=0,h=arr.size()-1,m;
        while(l<=h)
        {
            m=(l+h)/2;
            
            //if(arr[m]==val) break;
            if(arr[m]<=val) l=m+1;
            else h=m-1;
        }
        
        arr.push_back(0);
        for(int i=arr.size()-1; i>l; --i)
        {
            arr[i]=arr[i-1];
        }
        arr[l]=val;
        
        return arr[arr.size()-k];
    }
};

typedef struct Treenode Treenode;
struct Treenode 
{
    int val;
    int cnt;
    Treenode *left;
    Treenode *right;
    Treenode() : val(0), cnt(1), left(NULL), right(NULL) {}
    Treenode(int x) : val(x), cnt(1), left(NULL), right(NULL) {}
};

//binary search tree
class KthLargest 
{
private:
    Treenode* root;
    int k;
    
public:
    KthLargest(int k, vector<int>& nums) 
    {
        root=NULL;
        for(auto i:nums)
        {
            Treenode* n=new Treenode(i);
            
            if(!root) root=n;
            else
            {
                Treenode* cur=root;
                Treenode* pre=NULL;
                
                while(cur)
                {
                    ++cur->cnt;
                    
                    pre=cur;
                    if(i>=cur->val) cur=cur->right;
                    else cur=cur->left;
                }
                
                if(i>=pre->val) pre->right=n;
                else pre->left=n;
            }
        }
        
        this->k=k;
    }
    
    int add(int val) 
    {
        Treenode* pre=NULL;
        Treenode* cur=root;
        Treenode* n=new Treenode(val);
        
        while(cur)
        {
            ++cur->cnt;
                    
            pre=cur;
            if(val>=cur->val) cur=cur->right;
            else cur=cur->left;
        }
        
        if(!root) root=n;
        else 
        {
            if(val>=pre->val) pre->right=n;
            else pre->left=n;
        }
        
        //BSTinorder(root);
        
        int kth=k;
        cur=root;
        while(cur)
        {
            //cout<<cur->cnt<<" ";
            if(cur->left && cur->right)
            {
                //cout<<cur->right->cnt+1<<"-"<<k<<" ";
                if(cur->right->cnt+1==kth) break;
                if(cur->right->cnt+1 > kth)
                {
                    cur=cur->right;
                }
                else
                {
                    kth=kth-cur->right->cnt-1;
                    cur=cur->left;
                }
            }
            else if(cur->left)
            {
                if(kth==1) break;
                
                cur=cur->left;
                --kth;
            }
            else if(cur->right)
            {
                if(cur->right->cnt+1==kth) break;
                
                cur=cur->right;
            }
            else
            {
                break;
            }
        }
        //cout<<"---"<<cur->val<<endl;
        return cur->val;
    }
    
    void BSTinorder(Treenode* n)
    {
        if(!n) return;
        
        BSTinorder(n->left);
        cout<<n->val<<"-"<<n->cnt<<" ";
        BSTinorder(n->right);
    }
};

//min heap
class KthLargest 
{
private:
    priority_queue<int, vector<int>, greater<int> > q;
    int k;
    
public:
    KthLargest(int k, vector<int>& nums) 
    {
        this->k=k;
        for(auto i:nums) add(i);
    }
    
    int add(int val) 
    {
        if(q.size()<k) q.push(val);
        else 
        {
            if(val>q.top())
            {
                q.pop();
                q.push(val);
            }
        }
        
        //cout<<"---"<<q.top()<<endl;
        return q.top();
    }
};
