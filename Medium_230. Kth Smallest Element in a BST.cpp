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

//2022-04-29
//recursive inorder
class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        int res;
        kth_inorder(root,k,res);
        
        return res;
    }
    
    void kth_inorder(TreeNode* root, int& k, int& res)
    {        
        if(!root) return;
        
        kth_inorder(root->left,k,res);
                
        --k;
        if(k<0) return;
        else if(k==0)
        {
            res=root->val;
            return;
        }
        //cout<<root->val<<" "<<k<<endl;
        
        kth_inorder(root->right,k,res);
    }
};

//2022-04-29
//iterative inorder
class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        int cnt=0;
        
        TreeNode* cur=root;
        stack<TreeNode*> s;
          
        while(!s.empty() || cur)
        {
            while(cur)
            {
                s.push(cur);
                cur=cur->left;
            }
            
            cur=s.top();
            ++cnt;
            //cout<<cnt<<" "<<cur->val<<endl;
            if(cnt==k) return cur->val;                
            s.pop();
            
            if(cur) cur=cur->right;
        }
        
        //dummy return
        return 0;
    }
};
