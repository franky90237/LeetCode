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

//2022-04-29
//recursive inorder
class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        int res;
        kth_inorder(root,k,res);
        
        return res;
    }
    
    void kth_inorder(TreeNode* root, int& k, int& res)
    {        
        if(!root) return;
        
        kth_inorder(root->left,k,res);
                
        --k;
        if(k<0) return;
        else if(k==0)
        {
            res=root->val;
            return;
        }
        //cout<<root->val<<" "<<k<<endl;
        
        kth_inorder(root->right,k,res);
    }
};

//2022-04-29
//iterative inorder
class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        int cnt=0;
        
        TreeNode* cur=root;
        stack<TreeNode*> s;
          
        while(!s.empty() || cur)
        {
            while(cur)
            {
                s.push(cur);
                cur=cur->left;
            }
            
            cur=s.top();
            ++cnt;
            //cout<<cnt<<" "<<cur->val<<endl;
            if(cnt==k) return cur->val;                
            s.pop();
            
            if(cur) cur=cur->right;
        }
        
        //dummy return
        return 0;
    }
};

//2022-04-30
//binary search
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) 
    {        
        int cnt=count_node(root->left);
        //cout<<root->val<<" "<<cnt<<endl;
        
        if(k<=cnt)
        {
            return kthSmallest(root->left,k);
        }
        else if(k>cnt+1)
        {
            return kthSmallest(root->right,k-cnt-1);
        }
        else
        {
            return root->val; 
        }                
    }
    
    int count_node(TreeNode* root)
    {
        if(!root) return 0;
        
        return 1+count_node(root->left)+count_node(root->right);
    }
};

//2022-08-01
//dfs, inorder
//time  : O(n)
//spcae : O(height of the tree)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {        
        vector<TreeNode*> s;     
                
        TreeNode* cur=root;        
        while(!s.empty() || cur)
        {
            while(cur)
            {
                s.push_back(cur);
                cur=cur->left;
            }
            
                        
            cur=s.back();
            s.pop_back();
            
            --k;
            if(k==0) break;
            
            cur=cur->right;
        }
        
        return cur->val;
    }
};

//2022-08-01
//binary search
//time  : O(n*n)
//spcae : O(height of the tree)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        int left_cnt=number_of_nodes(root->left);    
        
        if(k==left_cnt+1)
        {
            return root->val;
        }
        else if(k<left_cnt+1)
        {
            return kthSmallest(root->left,k);
        }
        else
        {
            return kthSmallest(root->right,k-1-left_cnt);
        }                
    }
    
    int number_of_nodes(TreeNode* root)
    {
        if(!root) return 0;
        return number_of_nodes(root->left) + 1 + number_of_nodes(root->right);
    }        
};

//2024-01-22
//Follw up
//time  : O(n)
//space : O(n)
class MyTreeNode
{
public:
    int val;
    int leftCnt=0;
    int rightCnt=0;
    MyTreeNode *left;
    MyTreeNode *right;
    MyTreeNode() : val(0), left(nullptr), right(nullptr) {}
    MyTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    MyTreeNode(int x, MyTreeNode *left, MyTreeNode *right) : val(x), left(left), right(right) {}    
    
    void insert(MyTreeNode* root, MyTreeNode* parent, TreeNode* node)
    {
        if(!node) return;
        
        if(!root)
        {
            if(node->val < parent->val) parent->left = new MyTreeNode(node->val);        
            else parent->right = new MyTreeNode(node->val);            
            return;
        }
                
        if(node->val > root->val)
        {
            ++root->rightCnt;
            insert(root->right, root, node);
        }
        else
        {
            ++root->leftCnt;
            insert(root->left, root, node);
        }
    }
    
    void print(MyTreeNode* root)
    {
        if(!root) return;
        
        cout<<root->val<<" | "<<root->leftCnt<<" "<<root->rightCnt<<endl;
        print(root->left);
        print(root->right);
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        MyTreeNode* myRoot = new MyTreeNode(root->val);
        clone(root, myRoot);        
        //myRoot->print(myRoot);
        
        return kthSmallest(myRoot, k);
    }
    
    void clone(TreeNode* root, MyTreeNode* myRoot)
    {
        if(!root) return;
        
        myRoot->insert(myRoot, NULL, root->left);
        myRoot->insert(myRoot, NULL, root->right);
        
        clone(root->left, myRoot);
        clone(root->right, myRoot);
    }
    
    int kthSmallest(MyTreeNode* root, int k) 
    {
        int leftNodes=root->leftCnt;
        if(k == leftNodes+1) return root->val;
        
        if(k < leftNodes+1) return kthSmallest(root->left, k);
        return kthSmallest(root->right, k-leftNodes-1);
    }
};
