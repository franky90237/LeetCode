//2023-08-22
//time  : O(n)
//spcae : O(1)
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int n=answerKey.size();
        map<char, int> freq;
        int left=0;
        int right=0;
        int mostCharCntSoFar=0;
        for(; right<n; ++ right)
        {
            ++freq[answerKey[right]];
            mostCharCntSoFar=max(mostCharCntSoFar, freq[answerKey[right]]);
            if(right-left+1-mostCharCntSoFar > k)
            {
                --freq[answerKey[left]];
                ++left;
            }
        }
        
        return right-left;
    }
};

//2023-10-21
//time  : O(n)
//space : O(1)
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) 
    {
        int n=answerKey.size();
        
        string targetChar="TF";
        int ans=0;
        for(auto c: targetChar)
        {
            int cnt=0;
            int left=0;
            for(int right=0; right<n; ++right)
            {
                if(answerKey[right] == c) ++cnt;
                while(right-left+1 - cnt > k)
                {
                    if(answerKey[left] == c) --cnt;
                    ++left;
                }
                
                ans = max(ans, right-left+1);
            }
        }
        
        return ans;
    }
};
