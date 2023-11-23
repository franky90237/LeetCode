//203-11-23
//time  : O(n)
//space : O(h), h is the height of the tree
class Solution 
{
private:
    int ans=0;
    
public:
    int maxAncestorDiff(TreeNode* root) 
    {
        solve(root);
        return ans;
    }
    
    vector<int> solve(TreeNode* root)
    {        
        vector<int> left{root->val, root->val};
        if(root->left) left=solve(root->left);
        
        vector<int> right{root->val, root->val};
        if(root->right) right=solve(root->right);
        
        int maxDiffL=max(abs(root->val-left[0]), abs(root->val-left[1]));
        int maxDiffR=max(abs(root->val-right[0]), abs(root->val-right[1]));
        ans=max(ans, max(maxDiffL, maxDiffR));
        
        return {min(root->val, min(left[0], right[0])), max(root->val, max(left[1], right[1]))};
    }
};
