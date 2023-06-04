//2023-06-04
class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) 
    {
        vector<vector<int>> nums;
        format(mat, nums);
        sort(nums.begin(), nums.end());
        
        int m=mat.size();
        int n=mat[0].size();
        
        vector<int> maxRows(m, 0);
        vector<int> maxCols(n, 0);
        
        for(int i=m*n-1; i>=0;)
        {
            unordered_map<int, int> rowMax;
            unordered_map<int, int> colMax;
            
            do
            {
                //int num=nums[i][0];
                int r=nums[i][1];
                int c=nums[i][2];
                int maximum=1+max(maxRows[r], maxCols[c]);
                rowMax[r] = max(rowMax[r], maximum);
                colMax[c] = max(colMax[c], maximum);
                
                --i;
            } while(i>=0 && nums[i+1][0] == nums[i][0]);
            
            for(auto& it: rowMax)
            {                 
                maxRows[it.first] = it.second; 
            }
                        
            for(auto& it: colMax)
            {                 
                maxCols[it.first] = it.second; 
            }
            //maxRows[r]=maximum;
            //maxCols[c]=maximum;
        }
        
        return max(*max_element(maxRows.begin(), maxRows.end()), 
                   *max_element(maxCols.begin(), maxCols.end()));
    }
    
    void format(vector<vector<int>>& mat, vector<vector<int>>& nums)
    {
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j) nums.push_back({mat[i][j], i, j});
        }
    }
};
