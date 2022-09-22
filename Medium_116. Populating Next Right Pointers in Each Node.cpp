/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

//2022-09-22
//bfs
//time  : O(n)
//space : O(2^n)
class Solution {
public:
    Node* connect(Node* root) 
    {
        if(!root) return NULL;
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* pre=NULL;
            int cnt=q.size();
            while(cnt > 0)
            {                
                Node* cur=q.front();
                q.pop();
                if(pre) pre->next=cur;
                pre=cur;
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                
                --cnt;
            }
            
            pre->next=NULL;
        }
        
        return root;
    }
};

//2022-09-22
//dfs
//time  : O(n)
//space : O(h), h is the height of the tree
class Solution {
public:
    Node* connect(Node* root) 
    {
        if(!root) return root;
        if(!root->left && !root->right) return root;
        
        root->left->next=root->right;
        if(root->next) root->right->next=root->next->left;
        
        connect(root->left);
        connect(root->right);
        
        return root;
    }
};
