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

//dp
class Solution 
{
private:
    //unordered_map< tuple<int,int,int>,vector<TreeNode*> > m;
    unordered_map< string,vector<TreeNode*> > m;
    
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
            vector<TreeNode*> subtree;
            
            string tmp(to_string(r-i)+to_string(left)+to_string(r-1));
            if(m.find(tmp)!=m.end())
            {
                subtree=m[tmp];
            }
            else
            {
                subtree=buildBST(r-i,left,r-1);
                m[tmp]=subtree;
            }
            
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
            vector<TreeNode*> subtree;
            string tmp(to_string(r+i)+to_string(r+1)+to_string(right));
            if(m.find(tmp)!=m.end())
            {
                subtree=m[tmp];
            }
            else
            {
                subtree=buildBST(r+i,r+1,right);
                m[tmp]=subtree;
            }
            
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

//more clever without dp
class Solution 
{
public:
    vector<TreeNode*> generateTrees(int n)
    {
        return buildBST(1,n);
    }
    
    vector<TreeNode*> buildBST(int start, int end)
    {
        //cout<<start<<" : "<<end<<endl;
        if(start>end) return {NULL};
        if(start==end) return {new TreeNode(start)};
        
        vector<TreeNode*> res;
        
        for(int mid=start; mid<=end; ++mid)
        {
            //cout<<"mid : "<<mid<<endl;
            vector<TreeNode*> left_subtree=buildBST(start,mid-1);
            vector<TreeNode*> right_subtree=buildBST(mid+1,end);
            
            for(auto& l:left_subtree)
            {
                for(auto& r: right_subtree)
                {
                    TreeNode* root=new TreeNode(mid);
                    root->left=l;
                    root->right=r;
                    
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
};
