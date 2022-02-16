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

//iterative
//time : O(log n)
//space : O(1)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        while(root)
        {
            if(root->val > val) root=root->left;
            else if(root->val < val) root=root->right;
            else return root;
        }
        
        return NULL;
    }
};

//recursivr
//time : O(log n)
//space : O(log n)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if(!root) return NULL;
        
        if(root->val > val) return searchBST(root->left,val);
        else if(root->val < val) return searchBST(root->right,val);
        else return root;
    }
};
