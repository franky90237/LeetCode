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
//space : O(height of the tree)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if(!root) return NULL;
        
        TreeNode* newRight=invertTree(root->left);
        TreeNode* newLeft=invertTree(root->right);
        
        root->left=newLeft;
        root->right=newRight;
        
        return root;
    }
};

//2022-07-29
//dfs (post-order)
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if(!root) return NULL;
        
        TreeNode* left_subtree=invertTree(root->left);
        TreeNode* right_subtree=invertTree(root->right);
        
        root->left=right_subtree;
        root->right=left_subtree;
        
        return root;
    }
};

//2022-07-29
//bfs
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if(!root) return NULL;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            
            TreeNode* tmp=cur->left;
            cur->left=cur->right;
            cur->right=tmp;
            
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        
        return root;
    }
};

//2022-07-29
//dfs iterative
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        /*
        s : 4 2 3
                
        */
            
        if(!root) return NULL;
        
        vector<TreeNode*> s;        
        
        TreeNode* cur=root;
        while(!s.empty() || cur)
        {
            while(cur)
            {                
                s.push_back(cur);
                cur=cur->left;
            }
            
            //for(auto& i:s) cout<<i->val<<" ";
            //cout<<endl;
            
            TreeNode* top=s.back();
            s.pop_back();
            
            TreeNode* tmp=top->left;
            top->left=top->right;
            top->right=tmp;
            
            cur=top->left;
        }
        
        return root;
    }
};

//2022-09-23
//recursive dfs preorder
//time  : O(n)
//space : O(n)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if(!root) return NULL;
        
        TreeNode* tmp=root->left;
        root->left=root->right;        
        root->right=tmp;
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};

//2024-01-20
//time  : O(n)
//spcae : O(n)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(!root) return NULL;
        
        deque<vector<TreeNode*>> level;
        level.push_back({root, root});
        
        while(!level.empty())
        {
            int size=level.size();
            
            for(int i=1; i<size; i+=2)
            {
                TreeNode* parent=level[i-1][1];
                parent->left=level[i][0];
                parent->right=level[i-1][0];
            }
            
            for(int i=0; i<size; ++i)
            {
                TreeNode* parent=level.front()[1];                
                TreeNode* cur=level.front()[0];
                level.pop_front();
                if(!cur || (!cur->left && !cur->right)) continue;
                
                level.push_back({cur->left, cur});
                level.push_back({cur->right, cur});
            }
        }
        
        return root;
    }
};
