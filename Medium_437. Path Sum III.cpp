/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//2022-07-29
//dfs + prefix sum memorization
//time  : O(n)
//soace : O(height of the tree)
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum)
    {
        int ans=0;
        
        unordered_map<long,int> prefix_sum;
        prefix_sum[0]=1;
        dfs(ans,root,0,targetSum,prefix_sum);
        
        return ans;
    }
    
    void dfs(int& ans, TreeNode* root, long currentSum, int targetSum, unordered_map<long,int>& prefix_sum)
    {
        if(!root) return;
        
        currentSum += root->val;
        long diff= currentSum-targetSum;
        if(prefix_sum.find(diff)!=prefix_sum.end()) 
        {
            cout<<root->val<<" "<<currentSum<<endl;
            ans += prefix_sum[diff];
        }
        
        prefix_sum[currentSum] += 1;
        
        dfs(ans,root->left,currentSum,targetSum,prefix_sum);
        dfs(ans,root->right,currentSum,targetSum,prefix_sum);
        
        if(prefix_sum[currentSum]==1) prefix_sum.erase(currentSum);
        else prefix_sum[currentSum] -= 1;        
    }
};
