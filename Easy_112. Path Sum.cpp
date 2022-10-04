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

//2022-07-27
//dfs
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if(!root) return false;        
        return dfs(root,targetSum);
    }
    
    bool dfs(TreeNode* root, int targetSum)
    {        
        if(!root) return false;
        if(!root->left && !root->right) return (targetSum-root->val)==0;
        
        //cout<<root->val<<" "<<targetSum<<endl;
        targetSum-=root->val;
        bool left  = dfs(root->left,targetSum);
        bool right = dfs(root->right,targetSum);
                
        return (left | right);        
    }
};

//2022-10-04
//time  : O(n)
//space : O(h), h is the height of the tree
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(!root) return false;
        
        targetSum-=root->val;
        if(!root->left && !root->right) return targetSum==0;
        
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};
