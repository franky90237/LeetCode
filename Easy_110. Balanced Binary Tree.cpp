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

//top down
//time = O(n*log(n))
class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        if(!root) return true;        
        if(abs(treeHeight(root->left) - treeHeight(root->right)) > 1) return false;        
        
        return isBalanced(root->left) && isBalanced(root->right);               
    }
    
    int treeHeight(TreeNode* root)
    {
        if(!root) return 0;
        
        int left_hight=treeHeight(root->left);
        int right_hight=treeHeight(root->right);
        
        return max(left_hight, right_hight)+1;
    }
};

//bottom up
//time = O(n)
class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        if(!root) return true;                       
        
        return treeHeight(root)!=-1;               
    }
    
    int treeHeight(TreeNode* root)
    {
        if(!root) return 0;
        
        int left_hight=treeHeight(root->left);
        if(left_hight==-1) return -1; 
            
        int right_hight=treeHeight(root->right);
        if(right_hight==-1) return -1; 
        
        if(abs(left_hight-right_hight) > 1) return -1;
        
        return max(left_hight, right_hight)+1;
    }
};

//2022-07-30
//dfs
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    bool isBalanced(TreeNode* root)
    {
        bool answer=true;
        dfs(root,answer);
        
        return answer;
    }
    
    int dfs(TreeNode* root, bool& answer)
    {
        if(!root) return 0;
                
        int left_depth = dfs(root->left,answer);
        int right_depth = dfs(root->right,answer);        
        if(abs(left_depth-right_depth)>=2) answer=false;
        
        return max(left_depth,right_depth) + 1;
    }
};

//2022-07-30
//dfs with one argument 
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    bool isBalanced(TreeNode* root)
    {       
        int answer=dfs(root);
        
        return answer!=-1;
    }
    
    int dfs(TreeNode* root)
    {
        if(!root) return 0;
                
        int left_depth = dfs(root->left);
        if(left_depth==-1) return -1;
        
        int right_depth = dfs(root->right);
        if(right_depth==-1) return -1;
        
        if(abs(left_depth-right_depth)>=2) return -1;
        
        return max(left_depth,right_depth) + 1;
    }
};

//2022-09-10
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    bool isBalanced(TreeNode* root)
    {
        bool ans=true;
        dfs(root,ans);
        
        return ans;
    }
    
    int dfs(TreeNode* root, bool& ans)
    {
        if(!root) return 0;
        
        int left=dfs(root->left,ans);
        int right=dfs(root->right,ans);
        
        if(!ans) return -1;
        
        if(abs(left-right)>=2) 
        {
            ans=false;
            return -1;
        }
        
        return 1+max(left,right);
    }
};

//2022-09-10
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    bool isBalanced(TreeNode* root)
    {                    
        return dfs(root)==-1 ? false : true;
    }
    
    int dfs(TreeNode* root)
    {
        if(!root) return 0;
        
        int left=dfs(root->left);
        if(left==-1) return -1;
        
        int right=dfs(root->right);
        if(right==-1) return -1;
                        
        if(abs(left-right)>=2) return -1;        
        return 1+max(left,right);
    }
};
