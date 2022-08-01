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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(!root) return new TreeNode(val);
        
        TreeNode* original=root;
        TreeNode* pre=NULL;
        
        while(root)
        {
            if(root->val > val)
            {
                pre=root;
                root=root->left;
            }
            else
            {
                pre=root;
                root=root->right;
            }
        }
        
        if(pre->val > val) pre->left=new TreeNode(val);
        else pre->right=new TreeNode(val);
        
        return original;
    }
};

//2022-08-01
//recursive
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        if(!root) return new TreeNode(val);
        
        if(val > root->val) 
        {
            if(root->right) insertIntoBST(root->right,val);
            else root->right=new TreeNode(val);
        }
        else
        {
            if(root->left) insertIntoBST(root->left,val);
            else root->left=new TreeNode(val);
        }
        
        return root;
    }
};
