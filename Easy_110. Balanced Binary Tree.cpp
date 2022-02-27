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

//top down
//time = O(n*log(n))
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

//bottom up
//time = O(n)
class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        if(!root) return true;                       
        
        return treeHeight(root)!=-1;               
    }
    
    int treeHeight(TreeNode* root)
    {
        if(!root) return 0;
        
        int left_hight=treeHeight(root->left);
        if(left_hight==-1) return -1; 
            
        int right_hight=treeHeight(root->right);
        if(right_hight==-1) return -1; 
        
        if(abs(left_hight-right_hight) > 1) return -1;
        
        return max(left_hight, right_hight)+1;
    }
};
