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

//2022-10-09
//time  : O(n)
//space : O(n)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) 
    {
        vector<int> nums;        
        stack<TreeNode*> s;
        TreeNode* cur=root;
        while(!s.empty() || cur)
        {
            while(cur)
            {
                s.push(cur);
                cur=cur->left;
            }
            
            cur=s.top();
            s.pop();
            nums.push_back(cur->val);
            
            cur=cur->right;
        }
        
        /*for(auto& num: nums) cout<<num<<" ";
        cout<<endl;*/
        
        int l=0;
        int r=nums.size()-1;
        while(l < r)
        {
            int sum=nums[l]+nums[r];
            if(sum == k) return true;
            
            if(sum < k)
            {
                ++l;
            }
            else
            {
                --r;
            }
        }
        
        return false;
    }     
};
