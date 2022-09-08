//2022-05-27
//TLE
//time  : O(max(nums))
//space : O(max(nums))
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int n=nums.size();
        if(n==0) return 0;
        
        int max_num=abs(nums[0]);
        for(int i=1; i<n; ++i) max_num=max(max_num,abs(nums[i]));
        
        cout<<max_num<<endl;
        bool *buckets=new bool[2*max_num+1];
        memset(buckets,0,sizeof(bool)*(2*max_num+1));
        
        for(auto& num:nums) 
        {
            //cout<<num+max_num<<" ";
            buckets[num+max_num]=1;
        }
        //for(int i=0; i<=2*max_num; ++i) cout<<buckets[i]<<" ";
        
        int max_len=1;        
        for(int i=0; i<=2*max_num; ++i)
        {            
            if(buckets[i]==0) continue;
            
            int len=1;
            int j=i+1;
            while(j<=2*max_num && buckets[j]!=0)
            {
                ++j;
                ++len;
            }
            
            max_len=max(max_len,len);
            i=j-1;
        }
        
        return max_len;
    }
};

//2022-05-28
//time  : O(n)
//space : O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int n=nums.size();
        if(n==0) return 0;
        
        unordered_map<int,int> num_group;
        unordered_map<int,vector<int>> group_num;
        
        int group=0;
        for(auto& num:nums)
        {
            num_group[num]=group;
            group_num[group].push_back(num);
            ++group;
        }
        
        for(auto& num:nums)
        {
            int minus=num-1;
            int plus=num+1;
            
            int group_minus=(num_group.find(minus)!=num_group.end()) ? num_group[minus] : -1;
            int group_now=num_group[num];
            int group_plus=(num_group.find(plus)!=num_group.end()) ? num_group[plus] : -1;
            
            int group_minus_cnt=(group_minus!=-1) ? group_num[group_minus].size() : 0;
            int group_now_cnt=group_num[group_minus].size();
            int group_plus_cnt=(group_minus!=-1) ? group_num[group_minus].size(): 0;
            
            int max_group_cnt;
            int max_group;
            if(group_minus_cnt>=group_plus_cnt) 
            {
                max_group_cnt=group_minus_cnt;
                max_group=group_minus;
            }
            else 
            {
                max_group_cnt=group_plus_cnt;
                max_group=group_plus;
            }
            
            if(group_now_cnt>=max_group_cnt) 
            {
                max_group_cnt=group_now_cnt;
                max_group=group_now;
            }
            else 
            {
                max_group_cnt=max_group_cnt;
                max_group=max_group;
            }                    
            
            update(num_group,group_num,group_minus,max_group);
            update(num_group,group_num,group_now,max_group);
            update(num_group,group_num,group_plus,max_group);                        
        }
        
        /*for(auto& i:num_group)
        {
            printf("%d : %d \n",i.first, i.second);
        }*/
        
        int max_len=1;
        for(auto& i:group_num) max_len=max(max_len,(int)i.second.size());
        
        return max_len;
    }
    
    void update(unordered_map<int,int>& num_group, unordered_map<int,vector<int>>& group_num, int group, int max_group)
    {
        if(group!=-1 && group!=max_group)
        {
            for(auto i: group_num[group])
            {
                num_group[i]=max_group;
                group_num[max_group].push_back(i);
            }
        }
    }
};

//2022-05-30
//time  : O(n)
//space : O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> s;
        for(auto& num:nums) s.insert(num);
        
        int lcs=0;
        for(auto num:nums)
        {
            if(s.find(num-1)==s.end())
            {
                int cnt=1;
                while(s.find(num+1)!=s.end())
                {
                    ++cnt;
                    ++num;
                }
                
                lcs=max(lcs,cnt);
            }
        }
        
        return lcs;
    }
};

//2022-09-08
//MLE
//time  : O(n)
//space : O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {        
        /*
              0,0,0,1,1,1,0,0,1,1,1,1,0,0,0
        l = 0 0 0 0 1 2 3 0 0 1 2 3 4 0 0 0
        a = 0 0 0 0 1 2 3 3 3 3 3 3 4 4 4 4
        */
        
        const int SIZE=2*(1e9);        
        bool table[SIZE+1]={0};        
        
        int n=nums.size();
        int max_num=INT_MIN;
        for(int i=0; i<n ;++i)
        {
            //cout<<nums[i]<<" "<<nums[i]+1e9<<endl;
            int num=nums[i]+1e9;
            max_num=max(max_num,num);
            table[num]=1;
        }
        
        int ans=0;
        int len=0;
        for(int i=0; i<=max_num; ++i)
        {
            //cout<<i<<" "<<table[i]<<endl;
            if(table[i]==0)
            {                
                len=0;
            }
            else
            {
                ++len;
                ans=max(ans,len);
            }
        }
        
        return ans;
    }
};

//2022-09-08
//union find
//time  : O(n)
//space : O(n)
class union_find
{
private:
    //num : {parent, size}
    unordered_map<int,pair<int,int>> parent;
    
public:
    union_find(vector<int>& nums)
    {        
        for(auto& num:nums) 
        {
            parent[num]={num,1};
        }
    }
    
    void combine(int a, int b)
    {
        int root_a=find(a);
        int root_b=find(b);
               
        if(parent[root_a].second > parent[root_b].second)
        {
            parent[root_b].first=root_a;
            parent[root_a].second+=parent[root_b].second;
        }
        else
        {
            parent[root_a].first=root_b;
            parent[root_b].second+=parent[root_a].second;
        }
        
        //cout<<a<<" : "<<parent[a].first<<" "<<parent[a].second<<endl;
        //cout<<b<<" : "<<parent[b].first<<" "<<parent[b].second<<endl<<endl;
    }
    
    int find(int a)
    {
        if(parent[a].first==a) return a;
        
        parent[a].first=find(parent[a].first);
        return parent[a].first;
    }
    
    int get_longest_length()
    {
        int max_len=0;
        for(auto& node:parent)
        {
            //cout<<node.first<<" - "<<node.second.first<<","<<node.second.second<<endl;
            max_len=max(max_len,node.second.second);
        }
        
        return max_len;
    }
};

class Solution 
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> table;
        union_find uf(nums);
        
        for(auto& num:nums)
        {
            if(table.count(num)>0) continue;
            
            table.insert(num);
            if(table.count(num-1)>0) uf.combine(num,num-1);
            if(table.count(num+1)>0) uf.combine(num,num+1);
        }
        
        return uf.get_longest_length();
    }
};
