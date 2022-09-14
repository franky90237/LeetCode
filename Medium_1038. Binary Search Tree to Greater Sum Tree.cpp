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

//2022-09-14
//time  : O(n)
//space : O(h), h is the height of the tree
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root)
    {
        int sum=0;
        change(root,sum);
        
        return root;
    }
    
    void change(TreeNode* root, int& sum)
    {
        if(!root) return;
        
        change(root->right,sum);
        
        sum+=root->val;
        root->val=sum;
        
        change(root->left,sum);
    }
};
