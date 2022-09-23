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

//2022-09-23
//dfs
//time  : O(n)
//space : O(h), h is the height of the tree
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root)
    {
        dfs(root->left, root->right, 1);
        return root;
    }
    
    void dfs(TreeNode* p1, TreeNode* p2, int level)
    {
        if(!p1 || !p2) return;
        
        if(level % 2 == 1)
        {
            int tmp=p1->val;
            p1->val=p2->val;
            p2->val=tmp;            
        }
        
        dfs(p1->left, p2->right, level+1);
        dfs(p1->right, p2->left, level+1);
    }
};
