//2022-10-26
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) 
    {
        vector<int> nEven, nOdd;
        vector<int> tEven, tOdd;        
        for(int i=0; i<nums.size(); ++i)
        {
            if(nums[i]%2==0) nEven.push_back(nums[i]);
            else nOdd.push_back(nums[i]);
            
            if(target[i]%2==0) tEven.push_back(target[i]);
            else tOdd.push_back(target[i]);
        }
        
        sort(nEven.begin(), nEven.end());
        sort(nOdd.begin(), nOdd.end());
        sort(tEven.begin(), tEven.end());
        sort(tOdd.begin(), tOdd.end());
        
        //print(nEven);
        //print(nOdd);
        //print(tEven);
        //print(tOdd);
        
        long long ans=0;
        int pn=0;
        int pt=0;
        while(pn < nEven.size())
        {
            int diff=abs(nEven[pn]-tEven[pt]);
            ans += diff/2;
            
            ++pn;
            ++pt;
        }
        
        pn=0;
        pt=0;
        while(pn < nOdd.size())
        {
            int diff=abs(nOdd[pn]-tOdd[pt]);
            ans += diff/2;
            
            ++pn;
            ++pt;
        }
        
        return ans/2;
    }
    
    void print(vector<int>& arr)
    {
        for(auto& i: arr) cout<<i<<" ";        
        cout<<endl;
    }
};
