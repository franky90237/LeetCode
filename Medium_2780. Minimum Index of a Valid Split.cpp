//2023-07-17
//time  : O(n)
//spcae : O(n)
class Solution {
public:
    int minimumIndex(vector<int>& nums) 
    {
        int n=nums.size();
        if(n == 1) return -1;
        
        vector<int> prefix(n, -1);
        vector<int> suffix(n, -1);                
        unordered_map<int, int> freq;
        map<int, int> cnt;
        
        for(int i=0; i<n-1; ++i)
        {
            ++freq[nums[i]];
            cnt[freq[nums[i]]]=nums[i];
            int maxCnt=(cnt.rbegin())->first;
            if(2*maxCnt > i+1) prefix[i]=(cnt.rbegin())->second;            
            
            //cout<<prefix[i]<<" ";
        }
        //cout<<endl;
        
        freq.clear();
        cnt.clear();
        for(int i=n-1; i>=1; --i)
        {
            ++freq[nums[i]];
            cnt[freq[nums[i]]]=nums[i];
            int maxCnt=(cnt.rbegin())->first;
            if(2*maxCnt > n-i) suffix[i]=(cnt.rbegin())->second;
            
            //cout<<suffix[i]<<" ";
        }
        
        for(int i=0; i<n-1; ++i)
        {
            if(prefix[i] == suffix[i+1] && prefix[i] != -1) return i;
        }
        
        return -1;
    }
};

//2023-07-17
//time  : O(n)
//spcae : O(n)
class Solution {
public:
    int minimumIndex(vector<int>& nums) 
    {
        int n=nums.size();
        if(n == 1) return -1;
        
        vector<int> prefix(n, -1);
        vector<int> suffix(n, -1);
        unordered_map<int, int> freqP, freqS;    
        
        for(int i=0; i<n-1; ++i)
        {
            ++freqP[nums[i]];
            if(2*freqP[nums[i]] > i+1) prefix[i]=nums[i];
            else if(i-1 >= 0 && 2*freqP[prefix[i-1]] > i+1) prefix[i]=prefix[i-1];
            
            //cout<<prefix[i]<<" ";
        }
        //cout<<endl;
                
        for(int i=n-1; i>=1; --i)
        {
            ++freqS[nums[i]];            
            if(2*freqS[nums[i]] > n-i) suffix[i]=nums[i];
            else if(i+1 < n && 2*freqS[suffix[i+1]] > n-i) suffix[i]=suffix[i+1];
            
            //cout<<suffix[i]<<" ";
        }
        
        for(int i=0; i<n-1; ++i)
        {
            if(prefix[i] == suffix[i+1] && prefix[i] != -1) return i;
        }
        
        return -1;
    }
};
