//2023-02-07
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2)
    {
        int min_val=INT_MAX;
        
        unordered_map<int, int> f1;
        unordered_map<int, int> f2;        
        
        for(auto c: basket1)
        {
            ++f1[c];
        }
        
        for(auto c: basket2)
        {
            ++f2[c];
        }                
        
        unordered_map<int, int> freq;
        
        for(auto& it: f1)
        {
            int val=it.first;
            int cnt1=it.second;            
            int cnt2=0;
            if(f2.find(val) != f2.end()) 
            {
                cnt2=f2[val];
                f2.erase(val);
            }
            
            if((cnt1 + cnt2) % 2 == 1) return -1;
            
            int cnt = max(cnt1, cnt2) - min(cnt1, cnt2);
            if(cnt > 0)
            {
                freq[val]=cnt;
            }
            
            min_val=min(min_val, val);
        }
        
        for(auto& it: f2)
        {
            int val=it.first;
            int cnt2=it.second;            
            int cnt1=0;
            if(f1.find(val) != f1.end()) 
            {
                cnt1=f1[val];
            }
            
            if((cnt1 + cnt2) % 2 == 1) return -1;
            
            int cnt = max(cnt1, cnt2) - min(cnt1, cnt2);
            if(cnt > 0)
            {
                freq[val]=cnt;
            }
            
            min_val=min(min_val, val);
        }
        
        if(freq.size() == 0) return 0;
        
        vector<int> rest;
        for(auto& it: freq)
        {
            if(it.second % 2 == 1) return -1;
            //cout<<it.first<<endl;
            while(it.second > 0)
            {
                rest.push_back(it.first);
                --it.second;
            }
        }
       
        sort(rest.begin(), rest.end());
        /*        
        cout<<"min : "<<min_val<<endl;    
        for(int i=0; i<rest.size(); ++i)
        {
            cout<<rest[i]<<" ";
        }
        cout<<endl;
        */
        
        long long ans=0;
        
        int n=rest.size();
        int l=0;
        int r=n-1;
        
        while(l < r && 2*min_val >= rest[l])
        {
            ans += rest[l];
            
            ++l;
            --r;
            
            if(rest[l-1] == rest[l] && rest[r] == rest[r+1])
            {
                ++l;
                --r;
            }
        }
        
        while(l < r)
        {
            ans += 2*min_val;
            
            l += 2;
            r -= 2;
        }        
        
        return ans;
    }
};
