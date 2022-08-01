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

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root) return NULL;
        
        TreeNode* cur=root;
        TreeNode* pre=NULL;
        
        while(cur && cur->val!=key)
        {
            pre=cur;
            
            if(cur->val > key) cur=cur->left;
            else if(cur->val < key) cur=cur->right;
        }
        
        if(!cur) return root;
        if(cur==root) return deleteTarget(cur);
                
        if(pre->left==cur) pre->left=deleteTarget(cur);
        else pre->right=deleteTarget(cur);
        
        return root;
    }
    
    TreeNode* deleteTarget(TreeNode* target)
    {
        TreeNode* root=NULL;
        
        if(!target->left && !target->right) root=NULL;
        else if(target->left && !target->right) root=target->left;
        else if(!target->left && target->right) root=target->right;
        else
        {
            TreeNode* cur=target;
            TreeNode* pre=NULL;
            
            cur=cur->right;
            while(cur->left) 
            {
                pre=cur;
                cur=cur->left;
            }
            
            cur->left=target->left;
            if(pre) 
            {
                pre->left=cur->right;
                cur->right=target->right;
            }
            
            root=cur;
        }
        
        delete target;
        return root;
    }
};

//2022-08-01
//time  : O(log(n))
//space : O(height of the tree)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if(!root) return NULL;
        if(!root->left && !root->right)
        {
            if(root->val!=key) return root;
            else
            {
                delete root;
                return NULL;
            }
        }
        
        if(root->val==key)
        {
            TreeNode* pre_suc=NULL;
            TreeNode* suc=root;
            find_successor(root,pre_suc,suc);
            
            if(pre_suc!=root)
            {
                pre_suc->left=NULL;
                pre_suc->left=suc->right;
            }
            
            //cout<<pre_suc->val<<" "<<suc->val<<endl;
            if(suc)
            {
                suc->left=root->left;
                if(pre_suc->right!=suc) suc->right=root->right;
            }
            else
            {
                suc=root->left;                
            }
            
            delete root;
            return suc;
        }
        
        TreeNode* pre=find_key(root,NULL,key);
        if(!pre) return root;
        TreeNode* target= (pre->val < key) ? pre->right : pre->left;            
        //cout<<((pre) ? pre->val : -99)<<endl;
        
        if(!target->left && !target->right)
        {
            if(pre->val < key) pre->right=NULL;
            else pre->left=NULL;            
        }
        else if(!target->left || !target->right)
        {
            TreeNode* new_child;
            if(target->left) new_child=target->left;
            else new_child=target->right;
            
            if(pre->val < key) pre->right=new_child;
            else pre->left=new_child;
        }
        else
        {
            TreeNode* pre_suc=NULL;
            TreeNode* suc=target;
            find_successor(target,pre_suc,suc);
            
            if(pre_suc!=target)
            {
                pre_suc->left=NULL;
                pre_suc->left=suc->right;
            }
            
            if(pre->val < key) pre->right=suc;
            else pre->left=suc;
                        
            
            suc->left=target->left;
            if(pre_suc->right!=suc) suc->right=target->right;
        }
        
        delete target;        
        return root;
    }    
    
    TreeNode* find_key(TreeNode* root, TreeNode* pre, int key)
    {
        //cout<<root->val<<endl;
        if(!root) return NULL;
        if(root->val==key) return pre;        
        else if(root->val < key) return find_key(root->right,root,key);        
        else return find_key(root->left,root,key);
    }
    
    TreeNode* find_successor(TreeNode* root, TreeNode*& pre, TreeNode*& suc)
    {
        pre=suc;
        suc=root->right;
        
        while(suc && suc->left) 
        {
            pre=suc;
            suc=suc->left;
        }
        
        return suc;
    }
};
