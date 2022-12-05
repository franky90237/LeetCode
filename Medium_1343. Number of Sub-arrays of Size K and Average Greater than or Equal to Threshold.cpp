//2022-12-05
//time  : O(n)
//space : O(1)
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        int n=arr.size();
        if(n < k) return 0;
        
        int ans=0;
        int sum=0;
        for(int i=0; i<k; ++i) sum += arr[i];
        if(sum/k >= threshold) ++ans;
        
        for(int i=k; i<n; ++i)
        {
            sum -= arr[i-k];
            sum += arr[i];
            if(sum/k >= threshold) ++ans;
        }
        
        return ans;
    }
};
