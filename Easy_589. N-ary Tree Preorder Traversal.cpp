/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) 
    {
        if(!root) return {};
        
        vector<int> res;
        preorder(root,res);
        
        return res;
    }
    
    void preorder(Node* root, vector<int>& res)
    {
        if(!root) return;
        
        res.push_back(root->val);
        for(auto child:root->children) preorder(child,res);
        
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) 
    {
        if(!root) return {};
        
        vector<int> res;
        stack<pair<Node*,int>> s;
        Node* cur=root;
                
        while(!s.empty() || cur!=NULL)
        {
            while(cur)
            {
                s.push(pair<Node*,int>(cur,0));
                res.push_back(cur->val);
                
                if(cur->children.size()==0) {cur=NULL; break;}
                cur=cur->children.at(0);
            }
            
            pair<Node*,int> tmp=s.top();
            s.pop();
            //s.push(pair<Node*,int>(tmp.first,tmp.second+1));
            
            if(tmp.second+1 >= (tmp.first)->children.size()) cur=NULL;
            else 
            {
                s.push(pair<Node*,int>(tmp.first,tmp.second+1));
                cur=cur->children.at(tmp.second+1);
            }
        }
        
        
        return res;
    }    
};
