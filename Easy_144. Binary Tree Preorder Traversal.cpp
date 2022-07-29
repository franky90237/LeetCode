//2022-07-29
//iterative with one while condition
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        if(!root) return {};
        
        vector<int> ans;
        ans.push_back(root->val);
        
        vector<TreeNode*> stack;
        stack.push_back(root);
        
        TreeNode* cur=root;
        
        while(!stack.empty())
        {
            while(cur)
            {
                if(cur->right) stack.push_back(cur->right);
                if(cur->left) ans.push_back(cur->left->val);
                cur=cur->left;
            }
            
            cur=stack.back();            
            stack.pop_back();
            ans.push_back(cur->val);
        }
        
        ans.pop_back();
        
        return ans;
    }
};

//2022-07-29
//iterative with two while condition
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        if(!root) return {};
        
        vector<int> ans;
        vector<TreeNode*> stack;
        TreeNode* cur=root;
        
        while(!stack.empty() || cur)
        {
            while(cur)
            {
                if(cur->right) stack.push_back(cur->right);
                ans.push_back(cur->val);
                cur=cur->left;
            }
            
            if(stack.empty()) break;
            cur=stack.back();
            stack.pop_back();            
            //cout<<cur->val<<endl;
        }            
        
        return ans;
    }
};

//2022-07-29
//clear
//iterative with two while condition
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        if(!root) return {};
        
        vector<int> ans;
        vector<TreeNode*> stack;
        TreeNode* cur=root;
        
        while(!stack.empty() || cur)
        {
            while(cur)
            {                
                ans.push_back(cur->val);
                stack.push_back(cur);
                cur=cur->left;
            }
                    
            cur=stack.back();
            stack.pop_back();
            cur=cur->right;
            //cout<<cur->val<<endl;
        }            
        
        return ans;
    }
};

//2022-07-29
//clear
//iterative with one while condition
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        if(!root) return {};
        
        vector<int> ans;
        vector<TreeNode*> stack;
        stack.push_back(root);
        
        TreeNode* cur;
        
        while(!stack.empty())
        {
            cur=stack.back();
            stack.pop_back();
            ans.push_back(cur->val);
            
            if(cur->right) stack.push_back(cur->right);
            if(cur->left) stack.push_back(cur->left);
        }            
        
        return ans;
    }
};
