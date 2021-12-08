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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if(root==NULL) return {};
        
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* curr=root;
        
        s.push(curr);
        while(!s.empty())
        {
            while(curr!=NULL)
            {
                if(curr->left!=NULL) 
                {
                    s.push(curr->left);                    
                }
                curr=curr->left;
            }
            
            curr=s.top();
            s.pop();
            result.push_back(curr->val);
            //cout<<curr->val<<endl;
            
            if(curr->right!=NULL)
            {
                s.push(curr->right);                
            }
            curr=curr->right;
        }
        
        return result;
    }
};
