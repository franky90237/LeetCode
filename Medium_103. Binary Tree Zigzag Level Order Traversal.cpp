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

//2022-04-29
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        if(!root) return {};
        vector<vector<int>> res;
        
        queue<TreeNode*> q;
        
        int toggle=0;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            
            vector<int> tmp(n);
            int index=(toggle==0) ? 0 : n-1;
            
            for(int i=0; i<n; ++i)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
                tmp[index]=node->val;
                if(toggle==0) ++index;
                else          --index;
            }
            
            toggle=toggle^1;
            res.push_back(tmp);
        }
        
        return res;
    }
};
