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
//iterative, stack change first and second
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        if(!root) return {};
        
        vector<int> ans;
        vector<TreeNode*> s;
        
        TreeNode* cur=root;
        while(!s.empty() || cur)
        {
            while(cur)
            {
                if(cur->right) s.push_back(cur->right);
                s.push_back(cur);
                cur=cur->left;                                
            }
            
            TreeNode* tmp=s.back();
            s.pop_back();
            
            if(!s.empty() && tmp->right==s.back()) 
            {
                cur=s.back();
                s.pop_back();
                s.push_back(tmp);
            }
            else
            {                
                ans.push_back(tmp->val);
            }            
        }
        
        return ans;
    }
};

//2022-07-29
//iterative, remember the pre printed node
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        if(!root) return {};
        
        vector<int> ans;
        vector<TreeNode*> s;
        
        TreeNode* pre=NULL;
        TreeNode* cur=root;
        while(!s.empty() || cur)
        {
            while(cur)
            {               
                s.push_back(cur);
                cur=cur->left;                                
            }
            
            cur=s.back();
            
            if(!cur->right || cur->right==pre)
            {
                s.pop_back();
                ans.push_back(cur->val);
                pre=cur;
                cur=NULL;
            }
            else
            {
                cur=cur->right;
            }
        }
        
        return ans;
    }
};
