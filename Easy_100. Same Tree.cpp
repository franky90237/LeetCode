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

//recursive
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

//iterative
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        
        stack<TreeNode*> sp;
        stack<TreeNode*> sq;
        TreeNode* curp=p;
        TreeNode* curq=q;
        
        sp.push(curp);
        sq.push(curq);
        while(!sp.empty())
        {
            while(curp)
            {
                if(!check(curp->right,curq->right)) return false;
                sp.push(curp->right);
                sq.push(curq->right);
                
                curp=curp->left;
                curq=curq->left;
                
                if(!check(curp,curq)) return false;
            }
            
            curp=sp.top();
            sp.pop();
            curq=sq.top();
            sq.pop();
        }
        
        return true;
    }
    
    bool check(TreeNode* p, TreeNode* q)
    {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        return true;
    }
};

//2022-07-30
//dfs
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if(!p && !q) return true;
        if(!p || !q) return false;        
        if(p->val != q->val) return false;
        
        bool left=isSameTree(p->left,q->left);
        if(!left) return false;
        
        bool right=isSameTree(p->right,q->right);
        
        return (left && right);
    }
};
