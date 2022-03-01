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
