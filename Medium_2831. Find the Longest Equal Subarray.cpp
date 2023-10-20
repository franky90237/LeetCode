//2023-08-20
//time  : O(n)
//space : O(n)
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) 
    {
        unordered_map<int, vector<int>> groups;
        int n=nums.size();
        for(int i=0; i<n; ++i)
        {
            groups[nums[i]].push_back(i);
        }
        
        int ans=1;
        for(auto& it: groups)
        {
            ans=max(ans, getLongest(it.second, k));
        }
        
        return ans;
    }
    
    int getLongest(vector<int>& index, int k)
    {
        int n=index.size();
        int ans=0;
        int left=0;
        int right=0;
        for(; right<n; ++right)
        {
            int len=right-left+1;            
            while(index[right]-index[left]+1-len > k)
            {
                ++left;
            }
            
            ans=max(ans, right-left+1);
        }
        
        return ans;
    }
};

//2023-10-20
//time  : O(n)
//space : O(n)
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) 
    {
        int n=nums.size();
        unordered_map<int, int> cnt;
        
        int ans=0;
        int left=0;
        for(int right=0; right<n; ++right)
        {
            ++cnt[nums[right]];
            ans=max(ans, cnt[nums[right]]);
            
            int len=right-left+1;
            if(len-ans > k)
            {
                --cnt[nums[left]];
                ++left;
            }                        
        }
        
        return ans;
    }
};

//2023-10-20
//time  : O(nlong(n))
//space : O(n)
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) 
    {
        int n=nums.size();
        unordered_map<int, int> numCnt;
        map<int, int> cntCnt;
        
        int ans=0;
        int left=0;
        for(int right=0; right<n; ++right)
        {
            insert(numCnt, cntCnt, nums[right]);
            
            int len=right-left+1;
            while(left <= right && len - (cntCnt.rbegin())->first > k)
            {
                remove(numCnt, cntCnt, nums[left]);
                ++left;
                len=right-left+1;
            }
            
            ans = max(ans, (cntCnt.rbegin())->first);
        }
        
        return ans;
    }
    
    void insert(unordered_map<int, int>& numCnt, map<int, int>& cntCnt, int num)
    {
        int preCnt=numCnt[num];
        ++numCnt[num];                
        
        --cntCnt[preCnt];
        if(cntCnt[preCnt] == 0) cntCnt.erase(preCnt);
        ++cntCnt[preCnt+1];
    }    
    
    void remove(unordered_map<int, int>& numCnt, map<int, int>& cntCnt, int num)
    {
        int preCnt=numCnt[num];
        --numCnt[num];                
        
        --cntCnt[preCnt];
        if(cntCnt[preCnt] == 0) cntCnt.erase(preCnt);
        ++cntCnt[preCnt-1];
    }
};
