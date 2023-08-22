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
