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

//Inorder
//Time : O(n)
//Space : O(n)
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        if(!root) return true;
        
        stack<TreeNode*> s;
        long pre=(long)INT_MIN-1;
        
        while(!s.empty() || root)
        {
            while(root)
            {
                s.push(root);
                root=root->left;
            }
            
            root=s.top();
            s.pop();
            
            //cout<<pre<<" "<<root->val<<endl;
            if(pre>=root->val) return false;
            pre=root->val;
            
            root=root->right;
        }
        
        return true;
    }
};
