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

//2022-07-11
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return build(preorder,0,inorder,0,inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, int cur, vector<int>& inorder, int l, int r)
    {
        if(l>r) return NULL;
        //cout<<cur<<" : "<<l<<" "<<r<<endl;
        
        TreeNode* node=new TreeNode(preorder[cur]);
        if(l==r) return node;
        
        int mid=0;
        while(inorder[mid]!=preorder[cur]) ++mid;
        
        node->left=build(preorder,cur+1,inorder,l,mid-1);
        node->right=build(preorder,cur+mid-l+1,inorder,mid+1,r);                
        
        return node;
    }
};
