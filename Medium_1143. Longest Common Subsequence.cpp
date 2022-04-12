//2022-04-12
//TLE
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        return solve(text1,0,text2,0);
    }
    
    int solve(string& text1, int i1, string& text2, int i2) 
    {
        int j1=text1.size();
        int j2=text2.size();
        
        if(i1>=j1 || i2>=j2) return 0;
        
        if(text1[i1]==text2[i2]) return 1+solve(text1,i1+1,text2,i2+1);
        
        return max(solve(text1,i1+1,text2,i2),solve(text1,i1,text2,i2+1));
    }
};
