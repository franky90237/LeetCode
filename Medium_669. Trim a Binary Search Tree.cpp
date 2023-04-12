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

//2023-04-12
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        if(!root)
        {
            return NULL;
        }
                
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        if(!valid(root->val, low, high))
        {
            //cout<<root->val<<endl;
            TreeNode* newRoot = deleteNode(root);
            //if(!newRoot) cout<<"NULL"<<endl;
            //delete root;           
            root = newRoot;
        }
            
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root)
    {
        if(!root)
        {
            return NULL;
        }
        if(!root->left)
        {
            return root->right;
        }
        if(!root->right)
        {            
            return root->left;
        }
        
        TreeNode* newRoot = getSuccessor(root);
        return newRoot;
    }
    
    TreeNode* getSuccessor(TreeNode* root)
    {
        if(!root->right->left)
        {
            return root->right;
        }
        
        TreeNode* pre=root;
        TreeNode* cur=root->right;
        while(cur->left)
        {
            pre = cur;
            cur = cur->left;
        }
        
        pre->left=NULL;
        return cur;
    }
    
    bool valid(int val, int low, int high)
    {
        return val >= low && val <= high;
    }
};

//2023-04-12
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        if(!root)
        {
            return NULL;
        }
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        if(root->val > high)
        {
            return root->left;
        }
        else if(root->val < low)
        {
            return root->right;
        }
        
        return root;
    }
};
