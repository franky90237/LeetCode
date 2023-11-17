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

//inorder
//Time : O(n)
//Space : O(n)
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        if(!root) return true;
        
        stack<TreeNode*> s;
        long pre=(long)INT_MIN-1;
        
        while(!s.empty() || root)
        {
            while(root)
            {
                s.push(root);
                root=root->left;
            }
            
            root=s.top();
            s.pop();
            
            //cout<<pre<<" "<<root->val<<endl;
            if(pre>=root->val) return false;
            pre=root->val;
            
            root=root->right;
        }
        
        return true;
    }
};

//recursive check min and max
//Time : O(n)
//Space : O(n)
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        if(!root) return true;
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }
    
    bool isValidBST(TreeNode* root, long min, long max)
    {
        if(!root) return true;
        if(root->val<=min || root->val>=max) return false;
        return isValidBST(root->left,min,root->val) && isValidBST(root->right,root->val,max);
    }
};


class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        if(!root) return true;
        
        TreeNode* pre=find_predecessor(root);
        TreeNode* suc=find_successsor(root);
        
        if((pre && root->val<=pre->val) || (suc && root->val>=suc->val))  return false;
        
        return isValidBST(root->left) && isValidBST(root->right);
    }
    
    TreeNode* find_successsor(TreeNode* root)
    {
        root=root->right;
        if(!root) return root;
        
        while(root->left)
        {
            root=root->left;
        }
        
        return root;
    }
    
    TreeNode* find_predecessor(TreeNode* root)
    {
        root=root->left;
        if(!root) return root;
        
        while(root->right)
        {
            root=root->right;
        }
        
        return root;
    }    
};

//2022-07-13
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        return check(root,NULL,NULL);
    }
    
    bool check(TreeNode* root, TreeNode* predecessor, TreeNode* successor)
    {        
        if(!root) return true;
        //cout<<((predecessor) ? predecessor->val : -1)<<" "<<root->val<<" "<<((successor) ? successor->val : 9999999)<<endl;
        if((predecessor && predecessor->val >= root->val) || (successor && root->val >= successor->val)) return false;
        
        bool left=check(root->left,predecessor,root);
        if(!left) return false;
        
        bool right=check(root->right,root,successor);
        
        return (left && right);
    }
};

//2022-09-12
//time  : O(n)
//space : O(h), h is the height fo the tree
class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        return dfs(root,NULL,NULL);
    }
    
    bool dfs(TreeNode* root, TreeNode* smaller, TreeNode* bigger)
    {
        if(!root) return true;
        
        if((smaller && root->val <= smaller->val) || (bigger && root->val >= bigger->val)) return false;
        
        return dfs(root->left,smaller,root) && dfs(root->right,root,bigger);
    }
};

//2023-11-17
//time  : O(n)
//space : O(h)
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {       
        return solve(root)[0];
    }
    
    vector<int> solve(TreeNode* root)
    {    
        if(!root->left && !root->right)
        {            
            return {true, root->val, root->val};
        }
                        
        vector<int> left{true, root->val, root->val};
        if(root->left) left=solve(root->left);
        
        vector<int> right{true, root->val, root->val};
        if(root->right) right=solve(root->right);
        
        //cout<<root->val<<" | "<<left[1]<<" "<<left[2]<<" | "<<right[1]<<" "<<right[2]<<endl;
        
        if(!left[0] || !right[0]) return {false, 0, 0};
        if((root->val <= left[1] && root->left) || (root->val >= right[2] && root->right)) return {false, 0, 0};
        
        return {true, right[1], left[2]};
    }
};

/*
[2,1,3]
[10,5,null,1,4,null,null,3,6]
[10,2,null,1,4,null,null,3,15]
[5,14,null,1]
[0,null,1]
[5,4,6,null,null,3,7]
[5,3,null,1]
[0,null,1]
[2,2,2]
[34,-6,null,-21]
[120,70,140,50,100,130,160,20,55,75,110,119,135,150,200]
*/

//2023-11-17
//time  : O(n)
//space : O(h)
class Solution 
{
private:
    bool ans;
    long pre;
    
public:
    bool isValidBST(TreeNode* root) 
    {
        pre=LONG_MIN;
        ans=true;
        inorder(root);
        return ans;
    }
    
    void inorder(TreeNode* root)
    {
        if(!root || !ans) return;
        
        inorder(root->left);
        if(root->val <= pre)
        {
            ans=false;
            return;
        }
        pre=root->val;
        inorder(root->right);
    }
};
