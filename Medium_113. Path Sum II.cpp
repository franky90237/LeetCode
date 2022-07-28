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

//2022-07-28
//dfs + backtracking
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> num;
        
        dfs(root,ans,num,targetSum);
        return ans;
    }
    
    void dfs(TreeNode* root, vector<vector<int>>& ans, vector<int>& num, int targetSum)
    {
        if(!root) return;
        if(!root->left && !root->right)
        {
            if(targetSum-root->val==0) 
            {
                num.push_back(root->val);
                ans.push_back(num);
                num.pop_back();
            }
        }
        
        num.push_back(root->val);
        dfs(root->left,ans,num,targetSum-root->val);
        dfs(root->right,ans,num,targetSum-root->val);
        num.pop_back();
    }
};
