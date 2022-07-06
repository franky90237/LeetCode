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

//2022-07-06
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        return solve(root,subRoot,true);                  
    }
    
     bool solve(TreeNode* root, TreeNode* subRoot, bool begin)
     {
        if(!root) return (subRoot) ? false : true;
        if(!subRoot) return false;
        
        //cout<<root->val<<" "<<subRoot->val<<endl;
                
        if(root->val==subRoot->val)
        {
            bool ans=solve(root->left,subRoot->left,false) && solve(root->right,subRoot->right,false);
            if(ans) return true;
        }        
        
        //cout<<endl;
        if(begin) return solve(root->left,subRoot,true) || solve(root->right,subRoot,true);         
        return false;
     }
};
