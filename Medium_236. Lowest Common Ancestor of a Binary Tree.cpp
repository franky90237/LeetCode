/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//2022-07-31
//df, record the path
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        vector<vector<TreeNode*>> path;
        vector<TreeNode*> tmp;
        
        dfs(root,p,q,path,tmp);        
        if(path.size()==1) return path[0].back();
        
        int last=0;
        int size=min(path[0].size(),path[1].size());
        for(int i=0; i<size; ++i)
        {
            if(path[0][i]==path[1][i]) last=i;
        }         
        
        return path[0][last];
    }
    
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q, vector<vector<TreeNode*>>& path, vector<TreeNode*>& tmp)
    {
        if(!root) return;
        if(path.size()==2) return;
        
        tmp.push_back(root);
        if(root==p || root==q)
        {
            path.push_back(tmp);        
            tmp.pop_back();
            return;
        }
        
        dfs(root->left,p,q,path,tmp);
        dfs(root->right,p,q,path,tmp);
        tmp.pop_back();                
    }        
};
