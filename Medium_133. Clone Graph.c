/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if(node==NULL) return node;
        
        unordered_map<int,Node*> visited;
        return dfs_clone(node,visited);
    }
    
    Node* dfs_clone(Node* node, unordered_map<int,Node*>& visited)
    {
        if(visited.find(node->val)!=visited.end()) return visited.find(node->val)->second;
                             
        Node* n=new Node(node->val);        
        visited.insert({node->val,n});
        //print_node(*node);
        
        for(int i=0;i<node->neighbors.size();++i)
        {                                        
            Node* n_neighbor=dfs_clone(node->neighbors[i],visited);
            n->neighbors.push_back(n_neighbor);            
        }
        
        return n;
    }
    
    void print_node(Node& node)
    {
        cout<<node.val<<" : ";
        for(int i=0;i<node.neighbors.size();++i)
        {
            cout<<node.neighbors[i]->val<<" ";
        }
        cout<<endl;
        
    }
};
