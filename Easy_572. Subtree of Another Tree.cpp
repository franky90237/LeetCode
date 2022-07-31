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

//2022-07-06
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        return solve(root,subRoot,true);                  
    }
    
     bool solve(TreeNode* root, TreeNode* subRoot, bool begin)
     {
        if(!root) return (subRoot) ? false : true;
        if(!subRoot) return false;
        
        //cout<<root->val<<" "<<subRoot->val<<endl;
                
        if(root->val==subRoot->val)
        {
            bool ans=solve(root->left,subRoot->left,false) && solve(root->right,subRoot->right,false);
            if(ans) return true;
        }        
        
        //cout<<endl;
        if(begin) return solve(root->left,subRoot,true) || solve(root->right,subRoot,true);         
        return false;
     }
};

//2022-07-07
//clear base condition
//time  : O(n*m) ,n is #nodes in root tree, m is #nodes in subRoot tree 
//space : O(height of the tree)
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        return solve(root,subRoot,true);                  
    }
    
     bool solve(TreeNode* root, TreeNode* subRoot, bool begin)
     {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
         
        //cout<<root->val<<" "<<subRoot->val<<endl;
                
        if(root->val==subRoot->val)
        {
            bool find=solve(root->left,subRoot->left,false) && solve(root->right,subRoot->right,false);
            if(find) return true;
        }        
        
        //cout<<endl;
        if(begin) return solve(root->left,subRoot,true) || solve(root->right,subRoot,true);         
        return false;
     }
};

//2022-07-07
//clear using isSameTree
//time  : O(n*m) ,n is #nodes in root tree, m is #nodes in subRoot tree 
//space : O(height of the tree)
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
         if(!root) return false;
        
        if(isSameTree(root,subRoot)) return true; 
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    
     bool isSameTree(TreeNode* root, TreeNode* subRoot)
     {
         if(!root && !subRoot) return true;
         if(!root || !subRoot) return false;
         
         //cout<<root->val<<" "<<subRoot->val<<endl;
         
         if(root->val==subRoot->val) return isSameTree(root->left,subRoot->left) && isSameTree(root->right,subRoot->right);
         return false;
     }
};

//2022-07-31
//time  : O(n*n)
//space : O(height of the tree)
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        
        bool same=isSameTree(root,subRoot);
        if(same) return true;
        
        bool left=isSubtree(root->left,subRoot);
        bool right=isSubtree(root->right,subRoot);
        
        return left || right;
    }
    
    bool isSameTree(TreeNode* a, TreeNode* b)
    {
        if(!a && !b) return true;
        if(!a || !b) return false;
        if(a->val != b->val) return false;
        
        bool left  = isSameTree(a->left,b->left);
        bool right  = isSameTree(a->right,b->right);
        
        return left && right;
    }
};

//2022-07-31
//serialize and then find substring
//time  : O(n+m)
//space : O(n+m)
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;        
        
        string a=serialize(root);
        string b=serialize(subRoot);
        
        char* ca=a.data();
        char* cb=b.data();
        //cout<<ca<<endl<<cb<<endl;
        
        return strstr(ca,cb)!=NULL;
    }
    
    string serialize(TreeNode* root)
    {
        if(!root) return "n";
        
        string res= "," + to_string(root->val) + "," + serialize(root->left) + "," +  serialize(root->right);
        return res;
    }
};
