//2022-04-25
//TLE
class Solution {
private:
    struct HashFunction
    {
        size_t operator()(const tuple<int,int,int>& t) const
        {
            size_t h0 = hash<int>()(get<0>(t));
            size_t h1 = hash<int>()(get<1>(t));
            size_t h2 = hash<int>()(get<2>(t));
            
            return h0 ^ h1 ^ h2;
        }
    };
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n=nums.size();
        
        unordered_map<int,vector<int>> m;
        for(int i=0; i<n; ++i)
        {
            if(m.find(nums[i])==m.end())
            {
                vector<int> s;
                m[nums[i]]=s;
            }
            
            m[nums[i]].push_back(i);
        }
        
        if(n>=3 && m.size()==1)
        {
            if(m.begin()->first==0) return {{0,0,0}};
            else return {};
        }
        
        unordered_set<tuple<int,int,int>,HashFunction> res_s;
        for(int i=0; i<n; ++i)
        {
            twoSum(nums,res_s,m,i,-nums[i]);
        }
        
        vector<vector<int>> res;
        for(auto& it:res_s) res.push_back({get<0>(it),get<1>(it),get<2>(it)});
        
        return res;
    }
    
    void twoSum(vector<int>& nums, unordered_set<tuple<int,int,int>, HashFunction>& res, unordered_map<int,vector<int>>& m, int now, int target)
    {
        int n=nums.size();
        
        for(int i=now+1; i<n; ++i)
        {
            if(i==now) continue;
            
            int value=target-nums[i];
            auto it=m.find(value);
            if(it!=m.end())
            {
                for(auto& index:it->second)
                {
                    if(index>i && index>now)
                    {
                       vector<int> tmp({nums[now],nums[i],nums[index]});
                        sort(tmp.begin(),tmp.end());
                        res.insert(make_tuple(tmp[0],tmp[1],tmp[2]));
                    }
                }
            }
        }
    }
};

//2022-04-25
//sort the nums first
//time  : O(n*n)
//space : O(n)
class Solution {
private:
    struct HashFunction
    {
        size_t operator()(const tuple<int,int,int>& t) const
        {
            size_t h0 = hash<int>()(get<0>(t));
            size_t h1 = hash<int>()(get<1>(t));
            size_t h2 = hash<int>()(get<2>(t));
            
            return h0 ^ h1 ^ h2;
        }
    };
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        unordered_map<int,vector<int>> m;
        for(int i=0; i<n; ++i)
        {
            if(m.find(nums[i])==m.end())
            {
                vector<int> s;
                m[nums[i]]=s;
            }
            
            m[nums[i]].push_back(i);
        }
        
        if(n>=3 && m.size()==1)
        {
            if(m.begin()->first==0) return {{0,0,0}};
            else return {};
        }
        
        unordered_set<tuple<int,int,int>,HashFunction> res_s;
        for(int i=0; i<n; ++i)
        {
            if(i==0 || nums[i]!=nums[i-1]) twoSum(nums,res_s,m,i,-nums[i]);
        }
        
        vector<vector<int>> res;
        for(auto& it:res_s) res.push_back({get<0>(it),get<1>(it),get<2>(it)});
        
        return res;
    }
    
    void twoSum(vector<int>& nums, unordered_set<tuple<int,int,int>, HashFunction>& res, unordered_map<int,vector<int>>& m, int now, int target)
    {
        int n=nums.size();
        //cout<<"******"<<now<<" "<<nums[now]<<endl;
        
        for(int i=now+1; i<n; ++i)
        {
            if(i!=now+1 && nums[i]==nums[i-1]) continue;
            //cout<<i<<"   "<<nums[i]<<endl;
            
            int value=target-nums[i];
            auto it=m.find(value);
            if(it!=m.end())
            {
                for(auto& index:it->second)
                {
                    if(index>i && index>now)
                    {
                       vector<int> tmp({nums[now],nums[i],nums[index]});
                        sort(tmp.begin(),tmp.end());
                        res.insert(make_tuple(tmp[0],tmp[1],tmp[2]));
                    }
                }
            }
        }
        //cout<<endl;
    }
};

//2022-04-25
//time  : O(nlog(n))
//space : O(1)
class Solution {    
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> res;
        for(int i=0; i<n; ++i)
        {
            if(i!=0 && nums[i]==nums[i-1]) continue;
            
            int target=-nums[i];
            int left=i+1;
            int right=n-1;
            while(left<right)
            {
                int sum=nums[left]+nums[right];
                
                if(sum==target)
                {
                    res.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left]==res[res.size()-1][1]) ++left;
                    while(left<right && nums[right]==res[res.size()-1][2]) --right;
                }
                else if(sum>target) --right;
                else ++left;
            }
        }
        
        return res;
    }
};

//2022-07-19
//TLE
//twoSum(hash set)
//time  : O(n*n)
//space : O(n)
class Solution 
{
private: 
    struct comp
    {    
        bool operator()(const vector<int>& a, const vector<int>& b) const
        {
            if(a[0]==b[0] && a[1]==b[1]) return a[2]<b[2];
            else if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        }
    } comp;    
    
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        /*sort(nums.begin(),nums.end());
        vector<int> tmp;
        for(int i=0; i<nums.size(); ++i)
        {
            if(i==0 || nums[i-1]!=nums[i])
            {
                tmp.push_back(nums[i]);
            }
        }
        swap(tmp,nums);*/
        
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); ++i)
        {
            int target=0-nums[i];                        
            twoSum(nums,i,target,ans);                 
        }
        
        sort(ans.begin(),ans.end(),comp);
        
        vector<vector<int>> ans_without_duplicate;
        //if(!ans.empty()) ans_without_duplicate.push_back(ans[0]);
                
        for(int i=0; i<ans.size(); ++i)
        {
            if(i==0 || !same(ans[i-1],ans[i]))
            {
                ans_without_duplicate.push_back(ans[i]);
            }
        }        
        
        return ans_without_duplicate;
    }
    
    void twoSum(vector<int>& nums, int cur, int target, vector<vector<int>>& ans)
    {
        unordered_set<int> table;
        
        for(int i=0; i<nums.size() &&  i!=cur; ++i)
        {
            int diff=target-nums[i];
            
            if(table.find(diff)!=table.end())
            {                
                vector<int> tmp;
                tmp.push_back(nums[cur]);
                tmp.push_back(nums[i]);
                tmp.push_back(diff);
                
                sort(tmp.begin(),tmp.end());
                ans.push_back(tmp);
            }
            
            table.insert(nums[i]);
        }
    }
    
    bool same(vector<int>& pre, vector<int>& cur)
    {
        return (pre[0]==cur[0] && pre[1]==cur[1] && pre[2]==cur[2]);
    }
};

//2022-07-19
//sorting + twoSum(two poiner)
//time  : O(nlog(n))
//space : O(1)
class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());               
        
        vector<vector<int>> ans;        
        for(int i=0; i<n; ++i)
        {
            if(i!=0 && nums[i-1]==nums[i]) continue;
            //cout<<i<<" : "<<endl;
            
            int target=0-nums[i];
            int left=i+1;
            int right=(i==n-1) ? n-2 : n-1;
            while(left<right)
            {                
                int sum=nums[left]+nums[right];
                
                if(sum==target) 
                {                
                    ans.push_back({nums[i],nums[left],nums[right]});
                    //printf("%d, %d, %d \n",nums[i],nums[left],nums[right]);
                    
                    ++left;
                    while(left<right && nums[left-1]==nums[left]) ++left;
                    
                    --right;
                    while(left<right && nums[right]==nums[right+1]) --right;
                }
                else if(sum<target) ++left;                
                else --right;
            }
        }
        
        return ans;
    }
};
