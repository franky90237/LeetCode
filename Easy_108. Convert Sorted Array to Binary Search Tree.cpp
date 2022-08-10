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
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        TreeNode* root=NULL;
        
        return buildBST(nums,&root,0,nums.size()-1);
    }
        
    TreeNode* buildBST(vector<int>& nums, TreeNode** root, int l, int h)
    {
        if(l>h) return NULL;
        
        int m=(l+h)/2;
        
        TreeNode* cur;
        if(!(*root)) 
        {
            *root=new TreeNode(nums[m]);
            cur=*root;
        }
        else cur=new TreeNode(nums[m]);
        
            
        (cur)->left=buildBST(nums,&cur,l,m-1);
        (cur)->right=buildBST(nums,&cur,m+1,h);
        
        return cur;
    }
};

//2022-07-31
//dfs + binary search
//time  : O(n)
//space : O(lng(n))
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        int n=nums.size();
        return solve(nums,0,n-1);
    }
    
    TreeNode* solve(vector<int>& nums, int start, int end)
    {
        if(start>end) return NULL;
        if(start==end) return new TreeNode(nums[start]);
        
        int mid=start+(end-start)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        
        root->left=solve(nums,start,mid-1);
        root->right=solve(nums,mid+1,end);        
        //cout<<root->val<<endl;
        
        return root;
    }
};

//2022-08-10
//time  : O(n)
//space : O(log(n))
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return create_BST(nums,0,nums.size()-1);
    }
    
    TreeNode* create_BST(vector<int>& nums, int low, int high)
    {
        if(low>high) return NULL;
        
        int mid=low+(high-low)/2;
        
        TreeNode* cur=new TreeNode(nums[mid]);        
        cur->left=create_BST(nums,low,mid-1);
        cur->right=create_BST(nums,mid+1,high);
        
        return cur;
    }
};
