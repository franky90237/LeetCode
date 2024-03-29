//2024-03-29
//time  : O(n)
//space : O(n)
class Solution 
{
private:
    int res = 0;
    
public:
    int longestUnivaluePath(TreeNode* root) 
    {
        if(!root) return 0;
        
        dfs(root);
        return res-1;
    }
    
    int dfs(TreeNode* root)
    {
        if(!root) return 0;
        
        int lenL = dfs(root->left);
        int lenR = dfs(root->right);
        
        int sum = 0;
        
        if(root->left && root->val == root->left->val) sum += lenL;
        else lenL = 0;
        
        if(root->right && root->val == root->right->val) sum += lenR;
        else lenR = 0;
        
        res = max(res, sum + 1);
        
        return max(lenL, lenR) + 1;
        
    }    
};
