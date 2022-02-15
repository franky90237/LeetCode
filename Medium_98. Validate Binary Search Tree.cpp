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

//inorder
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

//recursive check min and max
//Time : O(n)
//Space : O(n)
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        if(!root) return true;
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }
    
    bool isValidBST(TreeNode* root, long min, long max)
    {
        if(!root) return true;
        if(root->val<=min || root->val>=max) return false;
        return isValidBST(root->left,min,root->val) && isValidBST(root->right,root->val,max);
    }
};
