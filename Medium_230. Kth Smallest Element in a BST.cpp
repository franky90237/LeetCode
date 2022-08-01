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

//2022-04-30
//binary search
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) 
    {        
        int cnt=count_node(root->left);
        //cout<<root->val<<" "<<cnt<<endl;
        
        if(k<=cnt)
        {
            return kthSmallest(root->left,k);
        }
        else if(k>cnt+1)
        {
            return kthSmallest(root->right,k-cnt-1);
        }
        else
        {
            return root->val; 
        }                
    }
    
    int count_node(TreeNode* root)
    {
        if(!root) return 0;
        
        return 1+count_node(root->left)+count_node(root->right);
    }
};

//2022-08-01
//dfs, inorder
//time  : O(n)
//spcae : O(height of the tree)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {        
        vector<TreeNode*> s;     
                
        TreeNode* cur=root;        
        while(!s.empty() || cur)
        {
            while(cur)
            {
                s.push_back(cur);
                cur=cur->left;
            }
            
                        
            cur=s.back();
            s.pop_back();
            
            --k;
            if(k==0) break;
            
            cur=cur->right;
        }
        
        return cur->val;
    }
};

//2022-08-01
//binary search
//time  : O(n*n)
//spcae : O(height of the tree)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        int left_cnt=number_of_nodes(root->left);    
        
        if(k==left_cnt+1)
        {
            return root->val;
        }
        else if(k<left_cnt+1)
        {
            return kthSmallest(root->left,k);
        }
        else
        {
            return kthSmallest(root->right,k-1-left_cnt);
        }                
    }
    
    int number_of_nodes(TreeNode* root)
    {
        if(!root) return 0;
        return number_of_nodes(root->left) + 1 + number_of_nodes(root->right);
    }        
};
