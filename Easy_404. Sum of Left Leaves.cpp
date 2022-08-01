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

//2022-08-01
//recursive
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        if(!root) return 0;
        
        int sum=0;
        if(root->left && !root->left->left && !root->left->right) sum+=root->left->val;
        else sum+=sumOfLeftLeaves(root->left);
        
        sum+=sumOfLeftLeaves(root->right);
        
        return sum;
    }
};

//2022-08-01
//iterative, inorder
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        if(!root) return 0;
        
        vector<TreeNode*> s;
        TreeNode* cur=root;
        
        int sum=0;
        while(!s.empty() || cur)
        {
            int cnt=1;
            while(cur)
            {
                s.push_back(cur);
                if(!cur->left && !cur->right && cnt!=1) 
                {
                    //cout<<cur->val<<endl;
                    sum+=cur->val;
                }
                cur=cur->left;
                ++cnt;
            }
            
            cur=s.back();
            s.pop_back();
            cur=cur->right;
        }
        
        return sum;
    }
};
