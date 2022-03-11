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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        vector<TreeNode*> res;
        unordered_map<string,int> m;
        
        traverse(root,m,res);
        return res;
    }
    
    string traverse(TreeNode* root, unordered_map<string,int>& m, vector<TreeNode*>& res)
    {
        if(!root) return "";
        
        string left_key=traverse(root->left,m,res);
        string right_key=traverse(root->right,m,res);
        string root_key=to_string(root->val)+","+left_key+","+right_key;
        //cout<<root_key<<endl;
        
        if(m.find(root_key)!=m.end() && m[root_key]==1) res.push_back(root);
        ++m[root_key];
        
        return root_key;
    }
};
