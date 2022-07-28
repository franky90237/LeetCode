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
//dfs
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    void flatten(TreeNode* root)
    {
        dfs(root);        
    }
    
    TreeNode* dfs(TreeNode* root)
    {
        if(!root) return NULL;
        if(!root->left && !root->right) return root;
              
        TreeNode* left=dfs(root->left);
        TreeNode* tmp=root->right;
        if(left)
        {
            root->right=root->left;
            root->left=NULL;
            left->right=tmp;
        }        
                
        TreeNode* right=dfs(tmp);
        
        //cout<<right<<endl;
        if(!right) return left;
        return right;
    }
};
