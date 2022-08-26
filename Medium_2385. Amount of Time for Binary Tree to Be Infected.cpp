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

//2022-08-26
//dfs
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    int amountOfTime(TreeNode* root, int start)
    {
        int ans=0;
        dfs(root,start,ans);        
        return ans;
    }
    
    vector<int> dfs(TreeNode* root, int start, int& ans)
    {
        if(!root) return {false,0};
        
        vector<int> left=dfs(root->left,start,ans);
        vector<int> right=dfs(root->right,start,ans);
        
        if(root->val==start)
        {
            ans=max(left[1],right[1]);
            return {true,0};
        }
        
        if(left[0]==true)
        {
            ans=max(ans,1+left[1]+right[1]);
            return {true,1+left[1]};
        }
        if(right[0]==true)
        {
            ans=max(ans,1+left[1]+right[1]);
            return {true,1+right[1]};
        }
        
        //cout<<root->val<<" "<<1+max(left[1],right[1])<<endl;
        return {false,1+max(left[1],right[1])};
    }
};
