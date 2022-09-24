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
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> ans;
        string s="";
        dfs(root, s, ans);
            
        return ans;
    }
    
    void dfs(TreeNode* root, string& s, vector<string>& ans)
    {
        if(!root) return;
        if(!root->left && !root->right)
        {                        
            ans.push_back(s + to_string(root->val));
            return;
        }
        
        string tmp=to_string(root->val) + "->";
        s+=tmp;
        
        dfs(root->left, s, ans);
        dfs(root->right, s, ans);
        
        s.resize(s.size()-tmp.size());
    }
};
