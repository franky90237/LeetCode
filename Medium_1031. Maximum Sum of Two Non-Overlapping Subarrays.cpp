//2023-05-19
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen)
    {
        int n=nums.size();
        int sumF=0;
        for(int i=0; i<firstLen; ++i)
        {
            sumF += nums[i];
        }
        
        int ans=0;
        int leftF=0;
        int rightF=firstLen-1;
        for(leftF=0; rightF<n; ++leftF, ++rightF)
        {
            //cout<<leftF<<"****\n";
            if(leftF != 0)
            {
                sumF += -nums[leftF-1] + nums[rightF];
            }
            
            int sumSL=getMaxSum(nums, 0, leftF-1, secondLen);
            int sumSR=getMaxSum(nums, rightF+1, n-1, secondLen);
            int maxSumS=max(sumSL, sumSR);
            ans=max(ans, sumF+maxSumS);
        }
        
        return ans;
    }
    
    int getMaxSum(vector<int>& nums, int begin, int end, int len)
    {
        if(end-begin+1 < len) return 0;
        
        int sum=0;
        for(int i=begin; i<begin+len; ++i)
        {
            sum += nums[i];
        }
        
        int maxSum=sum;
        for(int left=begin+1, right=begin+len; right<=end; ++left, ++right)
        {
            //cout<<left<<","<<right<<" | "<<sum<<endl;
            sum += -nums[left-1] + nums[right];
            maxSum=max(maxSum, sum);
        }
        
        return maxSum;
    }
};

//2023-05-23
//time  : O(n)
//space : O(n)
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) 
    {
        int n=nums.size();
        vector<int> prefixSum(n+1, 0);
        for(int i=1; i<=n; ++i)
        {
            prefixSum[i]=prefixSum[i-1]+nums[i-1];
        }
        
        return max(maxSum(prefixSum, firstLen, secondLen), maxSum(prefixSum, secondLen, firstLen));
    }
    
    int maxSum(vector<int>& prefixSum, int len1, int len2)
    {
        int n=prefixSum.size()-1;
        int res=0;
        int maxL=0;
        int left1=0, right1=left1+len1-1;
        int left2=right1+1, right2=left2+len2-1;
        for(; right2<n; ++left1, ++right1, ++left2, ++right2)
        {
            maxL=max(maxL, prefixSum[right1+1]-prefixSum[left1]);
            int curR=prefixSum[right2+1]-prefixSum[left2];
            res=max(res, maxL+curR);
        }
        
        return res;
    }
};
