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

//2022-09-14
//time  : O(n)
//sapce : O(h), h is the height of the tree
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root)
    {
        int bitmap=0;        
        return dfs(root,bitmap);
    }
    
    int dfs(TreeNode* root, int bitmap)
    {
        if(!root) return 0;
        
        bitmap = bitmap ^ (1<<root->val);
        //cout<<bitmap<<endl;
        
        if(!root->left && !root->right)
        {        
            return check(bitmap);
        }                
        
        return dfs(root->left,bitmap) + dfs(root->right,bitmap);
    }
    
    bool check(int bitmap)
    {        
        //cout<<"*****"<<bitmap<<endl;
        return (bitmap & (bitmap-1))==0;                
    }
};

//2022-09-14
//time  : O(n)
//sapce : O(h), h is the height of the tree
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root)
    {
        stack<pair<TreeNode*,int>> s;
        s.push({root,1<<root->val});
        
        int ans=0;
        
        while(!s.empty())
        {
            TreeNode* cur=s.top().first;
            int bitmap=s.top().second;
            s.pop();
            
            if(!cur->left && !cur->right)
            {
                ans+=check(bitmap);
            }
            
            if(cur->right)
            {
                s.push({cur->right, bitmap ^ (1<<cur->right->val)});
            }
            
            if(cur->left)
            {
                s.push({cur->left, bitmap ^ (1<<cur->left->val)});
            }
            
        }
        
        return ans;
        
    }      
    
    bool check(int bitmap)
    {        
        //cout<<"*****"<<bitmap<<endl;
        return (bitmap & (bitmap-1))==0;                
    }
};
