//2023-01-30
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) 
    {
        int n=weights.size();
        vector<int> scores;
        
        for(int i=1; i<n; ++i)
        {
            int score=weights[i-1]+weights[i];
            scores.push_back(score);
        }
        
        sort(scores.begin(), scores.end());
        
        long long ans=0;
        int l=0;
        int r=scores.size()-1;
        
        --k;
        while(k > 0)
        {
            int diff=scores[r]-scores[l];
            ans += diff;
            
            ++l;
            --r;
            --k;
        }
        
        return ans;
    }
};
