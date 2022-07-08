/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left,p,q);
        if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right,p,q);
        
        return root;
    }
};

//2022-07-08
//time  : O(n*n)
//space : O(height of the tree)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        TreeNode* ans=root;
        
        queue<TreeNode*> que;        
        que.push(root);
        while(!que.empty())
        {
            TreeNode* tmp=que.front();
            que.pop();
            
            if(solve(tmp,p,q)==2) ans=tmp;
            
            if(tmp->left) que.push(tmp->left);
            if(tmp->right) que.push(tmp->right);
        }
        
        
        return ans;
    }
    
    int solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {        
        if(!root) return 0;
        
        int left=solve(root->left,p,q);
        if(root==p || root==q) ++left;
        if(left==2) return 2;
        
        int right=solve(root->right,p,q);        
        return left+right;
    }
};

//2022-07-08
//time  : O(height of the tree)
//space : O(height of the tree)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left,p,q);
        else if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right,p,q);
        
        return root;
    }
};
