//2022-07-30
//TLE
//time  : O(2^k)
//space : O(k)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k)
    {
        /*
        maxPoints = max(cardPoints[0]+cardPoints[1:n],cardPoints[n]+cardPoints[0:n-1])
        */               
        
        return solve(cardPoints,0,cardPoints.size()-1,k);
    }
    
    int solve(vector<int>& cardPoints, int l, int r, int k)
    {
        if(k==0) return 0;
        
        int pick_left = cardPoints[l] + solve(cardPoints,l+1,r,k-1);
        int pick_right = cardPoints[r] + solve(cardPoints,l,r-1,k-1);
        
        return max(pick_left,pick_right);
    }
};

//2022-07-30
//MLE
//time  : O(k*n)
//space : O(k)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k)
    {
        /*
        maxPoints = max(cardPoints[0]+cardPoints[1:n],cardPoints[n]+cardPoints[0:n-1])
        */
        int n=cardPoints.size();
        vector<vector<vector<int>>> dp(k+1,vector<vector<int>>(n,vector<int>(n,-1)));
        
        return solve(dp,cardPoints,0,n-1,k);
    }
    
    int solve(vector<vector<vector<int>>>& dp, vector<int>& cardPoints, int l, int r, int k)
    {
        if(k==0) return 0;
        if(dp[k][l][r]!=-1) return dp[k][l][r];
        
        int pick_left = cardPoints[l] + solve(dp,cardPoints,l+1,r,k-1);
        int pick_right = cardPoints[r] + solve(dp,cardPoints,l,r-1,k-1);
        
        dp[k][l][r]=max(pick_left,pick_right);
        return dp[k][l][r];
    }
};
