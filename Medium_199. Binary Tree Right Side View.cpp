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

//2022-07-29
//time  : O(height of the tree)
//space : O(1)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        if(!root) return {};
        
        vector<int> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0; i<size; ++i)
            {
                TreeNode* tmp=q.front();
                q.pop();
                
                if(i==size-1) ans.push_back(tmp->val);
                
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            
            //cout<<ans.back();
        }
        
        return ans;
    }
};

//2022-07-30
//dfs
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ans;
        int level=0;
        
        dfs(root,level,ans);
        return ans;
    }
    
    void dfs(TreeNode* root,int level,vector<int>& ans)
    {
        if(!root) return;
        if(level==ans.size()) 
        {
            //cout<<root->val<<endl;
            ans.push_back(root->val);
        }
        
        dfs(root->right,level+1,ans);
        dfs(root->left,level+1,ans);
    }
};
