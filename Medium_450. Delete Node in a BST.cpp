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
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root) return NULL;
        
        TreeNode* cur=root;
        TreeNode* target=NULL;
        TreeNode* tp=NULL;
        
        while(cur)
        {
            tp=target;
            target=cur;
            
            if(cur->val > key) cur=cur->left;
            else if(cur->val < key) cur=cur->right;
            else break;
        }
        
        if(!cur) return root;
        
        if(!target->left && !target->right)
        {
            if(target==root)
            {
                root=NULL;
            }
            else
            {
                if(tp->left==target) tp->left=NULL;
                else tp->right=NULL;
            }
        }
        else if(target->left && !target->right)
        {
            if(target==root)
            {
                root=target->left;
            }
            else
            {
                if(tp->left==target) tp->left=target->left;
                else tp->right=target->left;
            }
        }
        else if(!target->left && target->right)
        {
            if(target==root)
            {
                root=target->right;
            }
            else
            {
                if(tp->left==target) tp->left=target->right;
                else tp->right=target->right;
            }
        }
        else
        {
            TreeNode* suc=target;
            TreeNode* sp=NULL;
            
            cur=target->right;
            while(cur)
            {
                sp=suc;
                suc=cur;
                cur=cur->left;
            }
            
            if(sp==target)
            {
                sp->right=suc->right;
            }
            else
            {
                sp->left=suc->right;
                suc->right=target->right;
            }
            
            suc->left=target->left;
            
            if(target==root)
            {
                root=suc;
            }
            else
            {
                if(tp->left==target) tp->left=suc;
                else tp->right=suc;
            }
        }
        
        delete target;
        return root;
    }
    
    void find_successor_and_parent(TreeNode* target, TreeNode** sp, TreeNode** suc)
    {
        target=target->right;
        while(target)
        {
            *sp=*suc;
            *suc=target;
            target=target->left;
        }
    }
};
