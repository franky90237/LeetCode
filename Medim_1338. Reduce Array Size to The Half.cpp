//2022-08-18
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    int minSetSize(vector<int>& arr)
    {
        unordered_map<int,int> table;
        for(auto& val:arr) ++table[val];
        
        multiset<int> cnt;
        for(auto& i:table) cnt.insert(-i.second);        
        
        int ans=0;
        int size=arr.size();
        for(auto& i:cnt)
        {
            ++ans;
            size+=i;
            if(size <= arr.size()/2) break;
        }
        
        return ans;
    }
};

//2022-08-18
//counting sort
//time  : O(n)
//space : O(n)
class Solution {
public:
    int minSetSize(vector<int>& arr)
    {
        unordered_map<int,int> table;
        for(auto& val:arr) ++table[val];
        
        int cnt[10001]={0};
        for(auto& i:table) ++cnt[i.second];
        
        int ans=0;
        int frequency=10000;
        int size=arr.size();
        while(size>arr.size()/2)
        {            
            while(cnt[frequency]==0) --frequency;
            
            ++ans;   
            size-=frequency;
            --cnt[frequency];
        }
        
        return ans;
    }
};
