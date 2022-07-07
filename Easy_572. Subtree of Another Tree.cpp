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

//2022-07-07
//clear base condition
//time  : O(n*m) ,n is #nodes in root tree, m is #nodes in subRoot tree 
//space : O(height of the tree)
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        return solve(root,subRoot,true);                  
    }
    
     bool solve(TreeNode* root, TreeNode* subRoot, bool begin)
     {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
         
        //cout<<root->val<<" "<<subRoot->val<<endl;
                
        if(root->val==subRoot->val)
        {
            bool find=solve(root->left,subRoot->left,false) && solve(root->right,subRoot->right,false);
            if(find) return true;
        }        
        
        //cout<<endl;
        if(begin) return solve(root->left,subRoot,true) || solve(root->right,subRoot,true);         
        return false;
     }
};

//2022-07-07
//clear using isSameTree
//time  : O(n*m) ,n is #nodes in root tree, m is #nodes in subRoot tree 
//space : O(height of the tree)
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
         if(!root) return false;
        
        if(isSameTree(root,subRoot)) return true; 
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    
     bool isSameTree(TreeNode* root, TreeNode* subRoot)
     {
         if(!root && !subRoot) return true;
         if(!root || !subRoot) return false;
         
         //cout<<root->val<<" "<<subRoot->val<<endl;
         
         if(root->val==subRoot->val) return isSameTree(root->left,subRoot->left) && isSameTree(root->right,subRoot->right);
         return false;
     }
};
