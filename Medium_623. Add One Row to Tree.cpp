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

//2022-10-05
//time  : O(n)
//space : O(d), d is the max number of any depth nodes  
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(depth==1)
        {
            TreeNode* n=new TreeNode(val, root, NULL);
            return n;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int d=1;
        while(d < depth-1)
        {
            int size=q.size();
            while(size > 0)
            {
                TreeNode* cur=q.front();
                q.pop();
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                
                --size;
            }
            
            ++d;
        }
        
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            
            TreeNode* l=new TreeNode(val, cur->left, NULL);
            TreeNode* r=new TreeNode(val, NULL, cur->right);
            cur->left=l;
            cur->right=r;
        }
        
        return root;
    }
};

//2022-10-05
//time  : O(n)
//space : O(h), h is the height of the tree
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(!root) return NULL;
        
        if(depth==1)
        {
            TreeNode* n=new TreeNode(val, root, NULL);
            return n;
        }
        
        if(depth == 2)
        {
            TreeNode* l=new TreeNode(val, root->left, NULL);
            TreeNode* r=new TreeNode(val, NULL, root->right);
            root->left=l;
            root->right=r;
            return root;
        }
        
        addOneRow(root->left, val, depth-1);
        addOneRow(root->right, val, depth-1);
            
        return root;
    }
};
