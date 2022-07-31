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

//2022-07-31
//dfs
//time  :  O(n)
//space : O(height of the tree)
class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if(!root) return true;
        
        return dfs(root->left,root->right);
    }
    
    bool dfs(TreeNode* l, TreeNode* r)
    {
        if(!l && !r) return true;
        if(!l || !r) return false;
        if(l->val != r->val) return false;
        
        int outer=dfs(l->left,r->right);
        if(!outer) return false;
        
        int inner=dfs(l->right,r->left);
        
        return outer && inner;        
    }
};

//2022-07-31
//bfs
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if(!root) return true;
        
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty())
        {
            TreeNode* l=q.front();
            q.pop();
            TreeNode* r=q.front();
            q.pop();
            
            if(!l && !r) continue;
            if(!l || !r) return false;
            if(l->val != r->val) return false;
            
            q.push(l->left);
            q.push(r->right);
            
            q.push(l->right);
            q.push(r->left);            
        }
        
        return true;
    }    
};
