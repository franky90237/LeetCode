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

class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        if(!root) return true;        
        if(abs(treeHeight(root->left) - treeHeight(root->right)) > 1) return false;        
        
        return isBalanced(root->left) && isBalanced(root->right);               
    }
    
    int treeHeight(TreeNode* root)
    {
        if(!root) return 0;
        
        int left_hight=treeHeight(root->left);
        int right_hight=treeHeight(root->right);
        
        return max(left_hight, right_hight)+1;
    }
};
