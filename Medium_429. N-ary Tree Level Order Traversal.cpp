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

//2022-09-05
//time  : O(n)
//space : O(m), m is the max number of each level's node
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        if(!root) return {};
        
        vector<vector<int>> ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> tmp;
            
            int size=q.size();
            while(size>0)
            {
                Node* n=q.front();
                q.pop();
                tmp.push_back(n->val);
                
                for(auto& child:n->children)
                {
                    q.push(child);
                }
                
                --size;
            }
            
            ans.push_back(tmp);
        }
        
        return ans;
    }
};
