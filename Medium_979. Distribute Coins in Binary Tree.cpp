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

 //2022-11-09
 //time  : O(n)
 //space : O(h), h is the height of the tree
class Solution {
public:
    int distributeCoins(TreeNode* root) 
    {
        int ans=0;
        dfs(root, ans);
        return ans;
    }

    int dfs(TreeNode* root, int& ans)
    {
        if(!root) return 0;

        int l=dfs(root->left, ans);
        int r=dfs(root->right, ans);
        ans += abs(l)+abs(r);
        
        return root->val + l + r - 1;
    }
};
