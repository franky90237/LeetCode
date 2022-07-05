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

//2022-07-05
//time  : O(n)
//space : O(hight of the tree)
class Solution {
public:
    int maxPathSum(TreeNode* root)
    {
        if(!root) return 0;        
        
        vector<int> res=solve(root);
        return max(res[0],max(res[1],res[2]));
    }
    
    vector<int> solve(TreeNode* root)
    {
        if(!root) return {0,-1000,-1000};
        
        int left=0;
        int right=0;
        int both=0;        
        
        vector<int> l=solve(root->left);
        left=l[0]+root->val;        
        
        vector<int> r=solve(root->right);
        right=r[0]+root->val;        
        
        if(root->val>=0) both=l[0]+r[0]+root->val;
        else 
        {
            if(!root->left && !root->right) both=-1000;
            else if(!root->left) both=r[0];
            else if(!root->right) both=l[0];
            else both=max(l[0]+r[0]+root->val,max(l[0],r[0]));
        }
        
        //cout<<root->val<<": "<<left<<" "<<right<<" "<<both<<endl;
        //vector<int> res={max(left,right),max(both,max(l[1],r[1])),max(root->val,max(l[2],r[2]))};
        //cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl<<endl;
        return {max(root->val,max(left,right)),max(both,max(l[1],r[1])),max(root->val,max(l[2],r[2]))};
    }
};
