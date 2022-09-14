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

//2022-07-11
//time  : O(n*n)
//space : O(height of the tree)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return build(preorder,0,inorder,0,inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, int cur, vector<int>& inorder, int l, int r)
    {
        if(l>r) return NULL;
        //cout<<cur<<" : "<<l<<" "<<r<<endl;
        
        TreeNode* node=new TreeNode(preorder[cur]);
        if(l==r) return node;
        
        int mid=0;
        while(inorder[mid]!=preorder[cur]) ++mid;
        
        node->left=build(preorder,cur+1,inorder,l,mid-1);
        node->right=build(preorder,cur+mid-l+1,inorder,mid+1,r);                
        
        return node;
    }
};

//2022-07-11
//use hash map to accelerate the look up time in the inorder
//time  : O(n)
//space : O(n)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        unordered_map<int,int> val_index;
        for(int i=0; i<inorder.size(); ++i) val_index[inorder[i]]=i;
        
        return build(preorder,0,inorder,0,inorder.size()-1,val_index);
    }
    
    TreeNode* build(vector<int>& preorder, int cur, vector<int>& inorder, int l, int r, unordered_map<int,int>& val_index)
    {
        if(l>r) return NULL;
        //cout<<cur<<" : "<<l<<" "<<r<<endl;
        
        TreeNode* node=new TreeNode(preorder[cur]);
        if(l==r) return node;
        
        int mid=val_index[preorder[cur]];        
        
        node->left=build(preorder,cur+1,inorder,l,mid-1,val_index);
        node->right=build(preorder,cur+mid-l+1,inorder,mid+1,r,val_index);                
        
        return node;
    }
};

//2022-09-14
//time  : O(n*n)
//space : O(h), h isthe height of the tree
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir)
    {
        //cout<<pl<<","<<pr<<" : "<<il<<","<<ir<<endl;
        
        if(il>ir) return NULL;
        
        TreeNode* root=new TreeNode(preorder[pl]);
        if(il==ir) return root;
        
        int mid=il;
        for(; mid<=ir; ++mid)
        {
            if(inorder[mid]==preorder[pl]) break;            
        }       
        
        int len=mid-il;
        root->left=build(preorder, pl+1, pl+len, inorder, il, mid-1);
        root->right=build(preorder, pl+len+1, pr, inorder, mid+1, ir);
        
        return root;
    }
};
