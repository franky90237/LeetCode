//2022-07-03
//TLE
//time  : O(n*n)
//space : O(n)
class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int res=0;
        for(int i=0; i<s.size(); ++i)
        {            
            int len=solve(i,i,s[i],s,k);
            res=max(res,len);
            //cout<<i<<" : "<<res<<" "<<len<<endl<<endl;
        }
        
        return res;
    }
    
    int solve(int l, int r, char c,string& s, int k)
    {
        int n=s.size();
        while(r+1<n && s[r+1]==c) ++r;
        while(l-1>=0 && s[l-1]==c) --l;
        
        //cout<<l<<" "<<r<<" "<<k<<endl;
        if(k==0) return r-l+1;        
        
        int right;
        if(r==n-1) right=r-l+1;
        else right=solve(l,r+1,c,s,k-1);
        
        int left;
        if(l==0) left=r-l+1;
        else left=solve(l-1,r,c,s,k-1);        
        
        return max(left,right);
    }
};

//2022-07-04
//sliding window + greedy
//time  : O(n)
//space : O(26)
class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int n=s.size();
        
        int charCount[26]={0};
        int maxCharCount=1;
        int ans=1;        
        int left=0;
        
        for(int right=0; right<n; ++right)
        {        
            ++charCount[s[right]-'A'];
            maxCharCount=max(maxCharCount,charCount[s[right]-'A']);
            
            //012345
            //AABBCD k=2
            //l=0, r=4, maxCharCount=2, curLen=5, 5-2=3 > k=2
            //l=1, r=4
            int curLen=right-left+1;
            if(curLen-maxCharCount > k)
            {
                --charCount[s[left]-'A'];
                ++left;                
            }
            
            ans=max(ans,right-left+1);
        }
        
        return ans;
    }
};

//2023-08-20
//time  : O(n)
//space : O(n)
class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        unordered_map<int, int> freq;
        int n=s.size();
        int ans=0;
        int left=0;
        int right=0;
        for(; right<n; ++right)
        {
            ++freq[s[right]];
            ans=max(ans, freq[s[right]]);
            if(right-left+1-ans > k)
            {
                --freq[s[left]];
                ++left;                
            }            
        }
        
        return right-left;
    }
};

//2023-08-21
//time  : O(nlog(n))
//space : O(n)
class MaxChar
{
private:
    unordered_map<char, int> charFreq;
    map<int, int> maxFreq;
    
public:
    MaxChar()
    {
        
    }
    
    void insert(char c)
    {
        if(charFreq.find(c) == charFreq.end())
        {
            charFreq[c]=1;
            ++maxFreq[1];
        }
        else
        {
            int preCnt=charFreq[c];
            ++charFreq[c];
            ++maxFreq[preCnt+1];
            --maxFreq[preCnt];
            if(maxFreq[preCnt] <= 0) maxFreq.erase(preCnt);
        }
    }
    
    void remove(char c)
    {
        int preCnt=charFreq[c];
        --charFreq[c];
        ++maxFreq[preCnt-1];
        --maxFreq[preCnt];
        if(maxFreq[preCnt] <= 0) maxFreq.erase(preCnt);
    }
    
    int most()
    {        
        return (maxFreq.rbegin())->first;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) 
    {        
        int n=s.size();
        MaxChar mc;
        
        int ans=0;
        int left=0;
        int right=0;
        for(; right<n; ++right)
        {
            mc.insert(s[right]);
            int most=mc.most();
            //cout<<left<<" "<<right<<" | "<<most<<endl;
            
            while(right-left+1-most > k)
            {
                mc.remove(s[left]);
                ++left;
                most=mc.most();                
            }
            
            ans=max(ans, right-left+1);
        }
        
        return ans;
    }
};
