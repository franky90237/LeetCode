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
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) 
    {
        vector<TreeNode*> res;
        for(int i=1; i<=n; ++i) 
        {
            vector<TreeNode*> tree=buildBST(i,1,n);
            //cout<<endl;
            res.insert(res.end(),tree.begin(),tree.end());
        }
        
        //cout<<res.size();
        return res;
    }
    
    vector<TreeNode*> buildBST(int r, int left, int right)
    {
        //cout<<" : "<<r<<","<<left<<","<<right<<endl;
        if(left==right) return {new TreeNode(r)};
        
        //left subtree
        vector<TreeNode*> tree;
        for(int i=1; r-i>=left; ++i)
        {
            vector<TreeNode*> subtree=buildBST(r-i,left,r-1);
            for(auto& t:subtree)
            {
                TreeNode* root=new TreeNode(r);
                root->left=t;
                tree.push_back(root);
            }
        }
        if(tree.size()==0)
        {
            TreeNode* root=new TreeNode(r);
            tree.push_back(root);
        }
        
        //right subtree
        vector<TreeNode*> res;
        for(int i=1; r+i<=right; ++i)
        {
            vector<TreeNode*> subtree=buildBST(r+i,r+1,right);
            for(auto& t:tree)
            {
                for(auto& st:subtree)
                {
                    TreeNode* root=new TreeNode(r,t->left,t->right);
                    root->right=st;
                    res.push_back(root);
                }
            }
        }
        
        if(res.size()==0) return tree;
        return res;
    }
};
