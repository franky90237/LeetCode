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

//2022-09-14
//time  : O(n)
//sapce : O(h), h is the height of the tree
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root)
    {
        int visited[10]={0};        
        return dfs(root,visited);
    }
    
    int dfs(TreeNode* root, int visited[])
    {
        if(!root) return 0;
        
        ++visited[root->val];
        
        /*cout<<root->val<<" : ";
        for(int i=0; i<10; ++i)
        {
            if(visited[i]>0) cout<<i<<" ";
        }        
        cout<<endl;*/
        
        if(!root->left && !root->right)
        {
            bool find=check(visited);
            --visited[root->val];
            return find;
        }
        
        int left=dfs(root->left,visited);
        int right=dfs(root->right,visited);
        --visited[root->val]; 
        
        return left + right;
    }
    
    bool check(int visited[])
    {        
        /*for(int i=0; i<10; ++i)
        {
            if(visited[i]>0) cout<<i<<","<<visited[i]<<" ";
        }        
        cout<<endl;*/
        
        int odd_cnt=0;
        
        for(int i=0; i<10; ++i)
        {
            if(visited[i]%2==1) ++odd_cnt;
            if(odd_cnt>=2) return false;
        }
        
        return true;
    }
};
