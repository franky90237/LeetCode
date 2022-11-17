//2022-11-13
//time  : O(n)
//space : O(n)
class Solution {
public:
    int minimumOperations(TreeNode* root)
    {
        vector<TreeNode*> v;
        v.push_back(root);
        
        int ans=0;
        int begin=0;
        bool insert=true;
        while(insert)
        {
            insert=false;
            
            int size=v.size();
            for(int i=begin; i<size; ++i)
            {
                if(v[i]->left) 
                {
                    v.push_back(v[i]->left);
                    insert=true;
                }
                if(v[i]->right) 
                {
                    v.push_back(v[i]->right);
                    insert=true;
                }                
            }
            
            map<int, int> m;           
            for(int i=begin; i<size; ++i)
            {
                int val=v[i]->val;
                m[val]=i;               
            }
                       
            int idx=begin;
            for(auto& it: m)
            {
                if(it.second != idx)
                {
                    int val=v[idx]->val;
                    m[val]=it.second;
                    swap(v[it.second], v[idx]);
                    ++ans;
                }
                
                ++idx;
            }
            
            //for(auto& i: v) cout<<i->val<<" ";
            //cout<<endl;            
            //cout<<ans<<endl;                        
            begin=size;
        }
        
        return ans;
    }
};

//2022-11-17
//time  : O(n)
//spcae : O(n)
class Solution {
public:
    int minimumOperations(TreeNode* root) 
    {
        int ans=0;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> arr;
            int size=q.size();
            while(size > 0)
            {
                TreeNode* node=q.front();
                q.pop();
                arr.push_back(node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
                --size;
            }
            
            ans += swapCount(arr);
        }
        
        return ans;
    }
    
    int swapCount(vector<int>& arr)
    {
        int n=arr.size();
        
        vector<int> idx(n);
        for(int i=0; i<n; ++i) idx[i]=i;
        
        sort(idx.begin(), idx.end(), [&](int a, int b)
             {
                 return arr[a] < arr[b];
             });
        
        int cnt=0;
        for(int i=0; i<n; ++i)
        {
            while(idx[i] != i)
            {
                int pairIdx=idx[i];
                swap(idx[i], idx[pairIdx]);
                ++cnt;
            }
        }
        
        return cnt;
    }
};
