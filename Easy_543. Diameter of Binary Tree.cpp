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

//2022-07-30
//dfs
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        int diameter=1;
        
        dfs(root,diameter);
        return diameter-1;
    }
    
    int dfs(TreeNode* root, int& diameter)
    {
        if(!root) return 0;
        
        int left=dfs(root->left,diameter);
        int right=dfs(root->right,diameter);
        
        diameter=max(diameter,left+right+1);
        //cout<<root->val<<" : "<<diameter<<" "<<left<<" "<<right<<endl;
        
        return max(left,right)+1;
    }
};
