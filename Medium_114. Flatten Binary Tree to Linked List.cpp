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

//2022-07-28
//dfs
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    void flatten(TreeNode* root)
    {
        dfs(root);        
    }
    
    TreeNode* dfs(TreeNode* root)
    {
        if(!root) return NULL;
        if(!root->left && !root->right) return root;
              
        TreeNode* left=dfs(root->left);
        TreeNode* tmp=root->right;
        if(left)
        {
            root->right=root->left;
            root->left=NULL;
            left->right=tmp;
        }        
                
        TreeNode* right=dfs(tmp);
        
        //cout<<right<<endl;
        if(!right) return left;
        return right;
    }
};

//2022-07-28
//dfs (reverse post-order)
//time  : O(n)
//space : O(height of the tree)
class Solution {    
public:
    void flatten(TreeNode* root)
    {
        /*
        1,2,3,4,5,6 
        
                1
              2   3
             4 5 6 7
             
        pre-order  :         1,2,4,5,3,6,7
        pos-torder :         4,5,2,6,7,3,1
        reverse post-order : 7,6,3,5,4,2,1
                
        */
        
        TreeNode* next=NULL;
        reverse_postorder(root,&next);
    }
    
    void reverse_postorder(TreeNode* root, TreeNode** next)
    {
        if(!root) return;
        
        reverse_postorder(root->right,next);
        reverse_postorder(root->left,next);
        
        root->right=*next;
        *next=root;
        root->left=NULL;
    }
};

//2022-07-28
//iterative
//time  : O(n)
//space : O(1)
class Solution {    
public:
    void flatten(TreeNode* root)
    {
        /*
        1,2,3,4,5,6 
        
                1             1                1              1
              2   3   ->       2      ->        2      ->      2
             4 5 6 7          4 5                4              4     
                                 3                5              5
                                6 7                3              3
                                                  6 7              6
                                                                    7
        */
        
        TreeNode* cur=root;
        
        while(cur)
        {
            if(cur->left)
            {
                TreeNode* last=cur->left;
                while(last->right) last=last->right;
                
                last->right=cur->right;
                cur->right=cur->left;
                cur->left=NULL;
            }
            
            cur=cur->right;
        }                
    }    
};
