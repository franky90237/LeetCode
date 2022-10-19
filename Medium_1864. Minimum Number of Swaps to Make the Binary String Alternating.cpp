//2022-10-19
//time  : O(n)
//spcae : O(n)
class Solution {
public:
    int minSwaps(string s) 
    {
        int n=s.size();
        if(n==1) return 0;
        
        int num[2]={0};
        for(auto& c: s)
        {
            ++num[c-'0'];
        }
        if(abs(num[1]-num[0]) >= 2) return -1;                
        
        string ans0;
        string ans1;        
        int val=0;
        for(int i=0; i<n; ++i)
        {
            ans0.push_back(val+'0');
            val = val ^ 1;
            ans1.push_back(val+'0');
        }
        
        int diff0=get_diff(s, ans0);
        int diff1=get_diff(s, ans1);                
        
        if(diff0%2 == 0 && diff1%2 == 0) return (diff0 < diff1) ? diff0/2 : diff1/2;
        if(diff0%2 == 0) return diff0/2;
        return diff1/2;
    }
    
    int get_diff(string& s, string& ans)
    {
        int cnt=0;
        for(int i=0; i<s.size(); ++i)
        {
            if(s[i] != ans[i]) ++cnt;
        }
        
        return cnt;
    }
};

/*
"111000"
"011010"
"1"
"0"
"10"
"11"
"00110011"
"11"
"00"
"11111"
"010"
"1110"
"100"
"001"
"011111"
*/
