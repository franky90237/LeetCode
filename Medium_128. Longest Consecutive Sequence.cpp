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
