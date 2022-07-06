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

//2022-07-06
//clear : using an answer variable to keep the maximum path sum form bottom to top at each node
class Solution {
public:
    int maxPathSum(TreeNode* root)
    {
        if(!root) return 0;
        
        int answer=INT_MIN;
        solve(root,answer);
        
        return answer;
    }
    
    int solve(TreeNode* root, int& answer)
    {
        if(!root) return 0;
        
        int left=solve(root->left,answer);
        int right=solve(root->right,answer);
        
        int maxPath_withoutBranch=max(root->val,max(left+root->val,right+root->val));
        int curMax=max(maxPath_withoutBranch,left+right+root->val);
        
        answer=max(answer,curMax);
        
        return maxPath_withoutBranch<0 ? 0 : maxPath_withoutBranch;
    }
};

//2022-07-06
//rederence : https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/603423/Python-Recursion-stack-thinking-process-diagram
//clear (reduces the max function call) : using an answer variable to keep the maximum path sum form bottom to top at each node
class Solution {
public:
    int maxPathSum(TreeNode* root)
    {
        if(!root) return 0;
        
        int answer=INT_MIN;
        solve(root,answer);
        
        return answer;
    }
    
    int solve(TreeNode* root, int& answer)
    {
        if(!root) return 0;
        
        int left=max(solve(root->left,answer),0);
        int right=max(solve(root->right,answer),0);
        
        int max_with_root=left+right+root->val;
        answer=max(answer,max_with_root);
        
        //int max_without_branch=max(left+root->val,right+root->val);
        //int max_with_branch=max(max_without_branch,left+right+root->val);
        
        //answer=max(answer,max_with_branch);
        
        return max(left+root->val,right+root->val);
    }
};
