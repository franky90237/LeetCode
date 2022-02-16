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
class BSTIterator 
{
private:
    TreeNode* root_node;
    TreeNode* curr;
    TreeNode* next_node;
    
public:
    BSTIterator(TreeNode* root) 
    {
        root_node=root;
        curr=NULL;
        next_node=NULL;
    }
    
    int next()
    {
        if(!curr)
        {
            TreeNode* temp=root_node;
            while(temp->left) temp=temp->left;
            curr=temp;
            
            return curr->val;
        }
        
        /*------------------*/
        
        
        if(next_node) 
        {
            curr=next_node;
            next_node=NULL;
            
            return curr->val;
        }
        
        /*------------------*/
        
        if(curr->right)
        {
            curr=curr->right;
            while(curr->left) curr=curr->left;
            
            return curr->val;
        }
        
        stack<TreeNode*> s;
        TreeNode* temp=root_node;
        while(temp!=curr)
        {
            s.push(temp);
            
            if(curr->val < temp->val) temp=temp->left;
            else temp=temp->right;
        }
        
        while(!s.empty())
        {
            temp=s.top();
            s.pop();
            if(temp->val > curr->val)
            {
                curr=temp;
                break;
            }
        }
        
        return curr->val;
    }
    
    bool hasNext() 
    {
        if(!root_node) return false;
        if(!curr) return true;
        if(next_node) return true;
        
        TreeNode* original=curr;
        
        if(curr->right)
        {
            curr=curr->right;
            while(curr->left) curr=curr->left;
            
            next_node=curr;
            curr=original;
            return true;
        }
        
        stack<TreeNode*> s;
        TreeNode* temp=root_node;
        while(temp!=curr)
        {
            s.push(temp);
            
            if(curr->val < temp->val) temp=temp->left;
            else temp=temp->right;
        }
        
        while(!s.empty())
        {
            temp=s.top();
            s.pop();
            if(temp->val > curr->val)
            {
                next_node=temp;
                return true;
            }
        }
        
        return false;
    }
};


