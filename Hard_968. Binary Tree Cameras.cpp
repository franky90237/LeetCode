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
class Solution 
{
private:
    enum state{CLEAN, COPIED, CAMERA};
    
public:
    int minCameraCover(TreeNode* root)
    {
        if(!root->left && !root>right) return 1;
        
        return solve(NULL,root);
    }
    
    int solve(TreeNode* pre, TreeNode* cur)
    {
        if(!cur) return 0;
        
        if(!pre)
        {
            int cnt=0;
            
            if(cur->left && cur->right)
            {
                cur->val=CAMERA;
                cnt=1;                                
            }
            else if(cur->left) cur->left->val=CAMERA;
            else if(cur->right) cur->right->val=CAMERA;
            
            int lenLeft=solve(cur,cur->left);
            int lenRight=solve(cur,cur->right);
            
            return cnt+lenLeft+lenRight;
        }
        
        if(pre->val==CAMERA)
    }
};
