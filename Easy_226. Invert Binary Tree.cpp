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

//2022-07-05
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if(!root) return NULL;
        
        TreeNode* newRight=invertTree(root->left);
        TreeNode* newLeft=invertTree(root->right);
        
        root->left=newLeft;
        root->right=newRight;
        
        return root;
    }
};

//2022-07-29
//dfs (post-order)
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if(!root) return NULL;
        
        TreeNode* left_subtree=invertTree(root->left);
        TreeNode* right_subtree=invertTree(root->right);
        
        root->left=right_subtree;
        root->right=left_subtree;
        
        return root;
    }
};
