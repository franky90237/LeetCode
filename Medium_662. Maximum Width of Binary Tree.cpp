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

//2022-07-31
//TLE
//bfs
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        /*
        [1] [3,2] [5,n,n,n]
        */
        
        queue<TreeNode*> q;
        q.push(root);
        
        int ans=1;
        while(!q.empty())
        {           
            bool isFind=false;
            int start=-1;
            int end=-1;
            int n=q.size();
            for(int i=0; i<n; ++i)
            {
                TreeNode* tmp=q.front();
                q.pop();
                
                if(tmp) 
                {                    
                    if(start==-1) start=i;
                    end=i;
                    
                    if(!isFind)
                    {
                        if(tmp->left) 
                        {
                            q.push(tmp->left);
                            isFind=true;
                        }
                        if(tmp->right || isFind) 
                        {
                            q.push(tmp->right);
                            isFind=true;
                        }
                    }
                    else
                    {
                        q.push(tmp->left);
                        q.push(tmp->right);
                    }
                }
                else if(!tmp && isFind)
                {
                    q.push(NULL);
                    q.push(NULL);
                }
            }
                                        
            if(start==-1) break;
            //cout<<end-start+1<<endl;
            ans=max(ans,end-start+1);
        }
        
        return ans;
    }    
};

//2022-07-31
//bfs
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {        
        queue<pair<TreeNode*,unsigned long long>> q;        
        q.push({root,1});
        
        unsigned long long ans=1;
        while(!q.empty())
        {
            unsigned long long start=q.front().second;
            unsigned long long end=start;
            
            int n=q.size();
            for(int i=0; i<n; ++i)
            {
                TreeNode* tmp=q.front().first;
                unsigned long long parent_val=q.front().second;
                q.pop();
                end=parent_val;
                
                if(tmp->left)
                {                    
                    q.push({tmp->left,parent_val*2});
                }
                if(tmp->right)
                {                    
                    q.push({tmp->right,parent_val*2+1});
                }                
            }
            
            //cout<<end-start+1<<endl;
            ans=max(ans,end-start+1);
        }
        
        return ans;
    }    
};

//2022-07-31
//bfs, optimize to prevent overflow
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        /*
        [1] [3,2] [5,n,n,n]
        */
        
        queue<pair<TreeNode*,unsigned int>> q;        
        q.push({root,0});
        
        unsigned int ans=1;
        while(!q.empty())
        {
            unsigned int min_val=q.front().second;
            unsigned int start=q.front().second-min_val;
            unsigned int end=start;
            
            int n=q.size();
            for(int i=0; i<n; ++i)
            {
                TreeNode* tmp=q.front().first;
                unsigned int parent_val=q.front().second-min_val;
                q.pop();
                end=parent_val;
                
                if(tmp->left)
                {
                    q.push({tmp->left,parent_val*2});
                }
                if(tmp->right)
                {                    
                    q.push({tmp->right,parent_val*2+1});
                }
            }
            
            //cout<<end-start+1<<endl;
            ans=max(ans,end-start+1);
        }
        
        return ans;
    }    
};
