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

//2022-07-30
//bfs
//time  : O(n)
//space : O(heifht of the tree)
class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if(!root) return 0;
        
        int depth=0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            ++depth;
            
            int size=q.size();
            for(int i=0; i<size; ++i)
            {
                TreeNode* tmp=q.front();
                q.pop();
                
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);                
            }                        
        }
        
        return depth;
    }
};

//2022-07-30
//dfs
//time  : O(n)
//space : O(heifht of the tree)
class Solution {
public:
    int maxDepth(TreeNode* root)
    {                
        int ans=0;
        int depth=0;
        dfs(root,depth,ans);
        
        return ans;
    }
    
    void dfs(TreeNode* root, int depth, int& ans)
    {
        if(!root) return;
        ++depth;
        
        if(!root->left && !root->right) 
        {
            ans=max(ans,depth);
            return;
        }
                
        dfs(root->left,depth,ans);
        dfs(root->right,depth,ans);
    }
};

//2022-07-30
//clear
//dfs
//time  : O(n)
//space : O(heifht of the tree)
class Solution {
public:
    int maxDepth(TreeNode* root)
    {       
        if(!root) return 0;
        
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);        
        
        return max(left_depth,right_depth) + 1;
    }      
};
