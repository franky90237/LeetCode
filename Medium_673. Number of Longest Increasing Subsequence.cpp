//2024-02-09
//time  : O(n*n)
//sapce : O(n)
struct item
{
    int len=0;
    int cnt=0;
    
    item() = default;
    item(int _len, int _cnt) : len(_len), cnt(_cnt) { }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<item> dp(n);
        dp[0] = item(1, 1);
        
        int maxLen = 1;
        for(int i=1; i<n; ++i)
        {        
            int curLen = 0;
            int curCnt = 1;
            for(int k=0; k<i; ++k)
            {
                if(nums[k] < nums[i]) 
                {
                    if(curLen < dp[k].len)
                    {
                        curLen = dp[k].len;
                        curCnt = dp[k].cnt;
                    }
                    else if(curLen == dp[k].len)
                    {
                        curCnt += dp[k].cnt;
                    }
                }            
            }
            
            dp[i] = item(curLen+1, curCnt);
            maxLen = max(maxLen, dp[i].len);
        }
        
        int res=0;
        for(int i=0; i<n; ++i)
        {
            //cout<<dp[i].len<<" "<<dp[i].cnt<<" | "<<endl;
            if(dp[i].len == maxLen) res += dp[i].cnt;
        }
        
        return res;
    }
};

//2024-02-09
//time  : O(nlog(n))
//sapce : O(n)
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        
        vector<vector<int>> arr;
        vector<vector<int>> cnt;
        
        arr.push_back({nums[0]});
        cnt.push_back({1});
        
        for(int i=1; i<n; ++i)
        {
            if(nums[i] > arr.back().back())
            {
                int idxArr = arr.size();               
                int idxSingleArr = bs(arr[idxArr-1], nums[i]);
                int sum = getSum(cnt[idxArr-1], idxSingleArr);
                //cout<<i<<" "<<idxSingleArr<<" "<<sum<<endl;                
                arr.push_back({nums[i]});
                cnt.push_back({sum});
            }
            else
            {
                int idxArr = bs(arr, nums[i]);
                if(idxArr == 0)
                {
                    if(nums[i] == arr[idxArr].back())
                    {
                        cnt[idxArr].back() += 1;
                    }
                    else
                    {
                        arr[idxArr].push_back(nums[i]);
                        cnt[idxArr].push_back(1 + cnt[idxArr].back());
                    }
                }
                else
                {
                    int idxSingleArr = bs(arr[idxArr-1], nums[i]);
                    int sum = getSum(cnt[idxArr-1], idxSingleArr);
                    //cout<<i<<" "<<idxSingleArr<<" "<<sum<<endl;
                    
                    if(nums[i] == arr[idxArr].back())
                    {
                        cnt[idxArr].back() += sum;
                    }
                    else
                    {
                        arr[idxArr].push_back(nums[i]);
                        cnt[idxArr].push_back(sum + cnt[idxArr].back());
                    }
                }
            }
        }        
        
        /*
        for(int i=0; i<arr.size(); ++i)
        {
            cout<<"[";
            for(int a : arr[i]) cout<<a<<" ";
            cout<<"] ";
        } cout<<endl;
                        
        for(int i=0; i<cnt.size(); ++i)
        {
            cout<<"[";
            for(int a : cnt[i]) cout<<a<<" ";
            cout<<"] ";
        } cout<<endl;
        */              
        
        return cnt.back().back();
    }
    
    int bs(vector<vector<int>>& arr, int target)
    {
        int low=0;
        int high=arr.size()-1;
        
        while(low < high)
        {
            int mid=low+(high-low)/2;
            if(target > arr[mid].back())
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        
        return low;
    }
    
    int bs(vector<int>& arr, int target)
    {
        //if(arr[0] < target) return 0;
        
        int low=0;
        int high=arr.size()-1;
        
        while(low < high)
        {
            int mid=low+(high-low)/2;
            if(target <= arr[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        
        return low;
    }
    
    int getSum(vector<int>& arr, int begin)
    {
        if(begin == 0) return arr.back();
        return arr.back() - arr[begin-1];
    }
};

//2024-02-09
//time  : O(nlog(n))
//sapce : O(n)
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        
        vector<vector<int>> arr;
        vector<vector<int>> cnt;
        
        arr.push_back({nums[0]});
        cnt.push_back({0, 1});
        
        for(int i=1; i<n; ++i)
        {
            int idxArr = binarySearch(0, arr.size()-1, nums[i], [&](int mid, int target)
                                      {
                                          return target <= arr[mid].back();
                                      });
            if(nums[i] > arr[idxArr].back()) ++idxArr;
                
            int curCnt = 1;
            if(idxArr - 1 >= 0)
            {
                int idxArrArr = binarySearch(0, arr[idxArr-1].size()-1, nums[i], [&](int mid, int target)
                                             {
                                                 return target > arr[idxArr-1][mid];
                                             });
                curCnt = cnt[idxArr-1].back() - cnt[idxArr-1][idxArrArr];
            }
            
            if(idxArr == arr.size())
            {
                arr.push_back({nums[i]});
                cnt.push_back({0, curCnt});
            }
            else
            {
                arr[idxArr].push_back(nums[i]);
                cnt[idxArr].push_back(curCnt + cnt[idxArr].back());
            }
        }
        
        /*
        for(int i=0; i<arr.size(); ++i)
        {
            cout<<"[";
            for(int a : arr[i]) cout<<a<<" ";
            cout<<"] ";
        } cout<<endl;
                        
        for(int i=0; i<cnt.size(); ++i)
        {
            cout<<"[";
            for(int a : cnt[i]) cout<<a<<" ";
            cout<<"] ";
        } cout<<endl;
        */     
        
        return cnt.back().back();
    }
    
    int binarySearch(int low, int high, int target, function<bool(int, int)> check)
    {        
        while(low < high)
        {
            int mid=low+(high-low)/2;
            if(check(mid, target))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return low;
    }    
};
