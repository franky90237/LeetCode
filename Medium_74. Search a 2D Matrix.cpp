//2022-08-03
//binary search
//time  : O(log(n))
//space : O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int low=0;
        int high=m*n-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int val_mid=matrix[mid/n][mid%n];
            
            if(val_mid==target) return true;
            else if(val_mid < target) low=mid+1;
            else high=mid-1;
        }
        
        return false;
    }
};

//2022-09-21
//time  : O(log(m*n))
//sapce : O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int l=0;
        int r=m*n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;            
            int mid_i = mid/n;
            int mid_j = mid%n;            
            
            if(target == matrix[mid_i][mid_j]) return true;
            else if(target > matrix[mid_i][mid_j]) l=mid+1;
            else r=mid-1;
        }
        
        return false;
    }
};
