//2024-01-15
//time  : O(n+x+n+y+nlog(n))
//space : O(n)
class Solution 
{
private:
    unsigned long long mod = 1000000007;
    unsigned long long x=27;
    
public:
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        vector<unsigned long long> prefix(s.size()+1, 0);        
        for(int i=1; i<=s.size(); ++i)
        {
            unsigned long long val = s[i-1]-'a'+1;
            unsigned long long cur=(x * prefix[i-1]) % mod;                            
            prefix[i] = (cur + val) % mod;
            //cout<<val<<" "<<cur<<endl;
        }
        
        //print(prefix);
        
        vector<int> idxA;
        getIdx(prefix, a, idxA);        
        if(idxA.empty()) return {};
        
        vector<int> idxB;
        getIdx(prefix, b, idxB);
        if(idxB.empty()) return {};        
                
        //print(idxA);
        //print(idxB);       
        
        vector<int> ans;
        for(int i=0; i<idxA.size(); ++i)
        {
            //cout<<i<<" "<<idxA[i]<<endl;
            
            auto it = lower_bound(idxB.begin(), idxB.end(), idxA[i]);
            if(it == idxB.end() && it != idxB.begin()) --it;
            
            int diff=abs(idxA[i]-*it);
            if(diff <= k) 
            {
                ans.push_back(idxA[i]);
                continue;
            }
            
            if(it != idxB.begin())
            {
                --it;
                diff=abs(idxA[i]-*it);
                if(diff <= k) ans.push_back(idxA[i]);
            }  
        }
        
        return ans;
    }
        
    void getIdx(vector<unsigned long long>& prefix, string& s, vector<int>& idx)
    {
        unsigned long long target=0;        
        for(int i=0; i<s.size(); ++i)
        {
            unsigned long long val = s[i]-'a'+1;
            unsigned long long cur = (x * target) % mod;
            target = (cur + val) % mod;                        
        }              
                
        int len = s.size();        
        int p = power(x, len);
        int left=0;
        int right=len-1;
        //cout<<target<<" --- "<<p<<" : ";
        for(; right<prefix.size()-1; ++right, ++left)
        {
            unsigned long long pre = (prefix[left]*p)%mod;
            unsigned long long cur = (prefix[right+1]-pre+mod)%mod;
            if(cur == target) idx.push_back(left);
            //cout<<"("<<prefix[right+1]<<" "<<prefix[left]<<") ";
        }
        
        //cout<<endl;
    }
    
    unsigned long long power(int a, int b)
    {
        if(a == 0) return 0;
        if(a == 1 || b == 0) return 1;
        if(b == 1) return a;
        
        unsigned long long val = power(a, b/2);
        unsigned long long res = val*val%mod;
        if(b%2 == 1) res = (res*a)%mod;
        
        return res;
    }
    
    template<typename T>
    void print(vector<T>& arr)
    {
        for(int i : arr) cout<<i<<" ";
        cout<<endl;
    }
};
