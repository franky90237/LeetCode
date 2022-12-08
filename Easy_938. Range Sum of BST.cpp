//2022-12-08
//time  : O(n)
//space : O(h), h is the height of tree
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        return dfs(root, low, high);
    }
    
    int dfs(TreeNode* root, int low, int high)
    {
        if(!root) return 0;                
        
        int l = dfs(root->left, low, high);
        int r = dfs(root->right, low, high);
        
        int val=(low<= root->val && root->val <= high) ? root->val : 0;
        return l + r + val;
    }
};
