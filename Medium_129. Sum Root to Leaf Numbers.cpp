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

//2022-09-12
//time  : O(n)
//space : O(h), h is the height of the tree
class Solution {
public:
    int sumNumbers(TreeNode* root)
    {
        int sum=0;
        int cur=0;
        dfs(root,cur,sum);
        
        return sum;
    }
    
    void dfs(TreeNode* root, int cur, int& sum)
    {
        if(!root) return;
        
        cur=cur*10+root->val;
        if(!root->left && !root->right) sum+=cur;
        
        dfs(root->left,cur,sum);
        dfs(root->right,cur,sum);
    }
};
