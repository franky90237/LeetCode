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

//clone graph with dfs
//clone graph with bfs
class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if(node==NULL) return node;
        
        //unordered_map<Node*,Node*> visited;
        //return dfs_clone(node,visited);
        
        return bfs_clone(node);
    }
    
    Node* dfs_clone(Node* node, unordered_map<Node*,Node*>& visited)
    {
        if(visited.find(node)!=visited.end()) return visited.find(node)->second;
                             
        Node* n=new Node(node->val);        
        visited.insert({node,n});
        //print_node(*node);
        
        for(int i=0;i<node->neighbors.size();++i)
        {                                        
            Node* n_neighbor=dfs_clone(node->neighbors[i],visited);
            n->neighbors.push_back(n_neighbor);            
        }
        
        return n;
    }
    
    Node* bfs_clone(Node* node)
    {
        unordered_map<Node*,Node*> visited;
        queue<Node*> q;
        
        q.push(node);
        while(!q.empty())
        {
            Node* original_node=q.front();
            q.pop();
            //print_node(*original_node);
            
            Node* copied_node;
            if(visited.find(original_node)==visited.end())
            {
                copied_node=new Node(original_node->val);
                visited.insert({original_node,copied_node});
            }
            else
            {
                copied_node=visited[original_node];
            }
            
            for(int i=0;i<original_node->neighbors.size();++i)
            {
                Node* copied_node_neighbor;
                if(visited.find(original_node->neighbors[i])==visited.end())
                {
                    copied_node_neighbor=new Node(original_node->neighbors[i]->val);
                    visited.insert({original_node->neighbors[i],copied_node_neighbor});
                    
                    q.push(original_node->neighbors[i]);
                }
                else
                {
                    copied_node_neighbor=visited[original_node->neighbors[i]];
                }
                
                copied_node->neighbors.push_back(copied_node_neighbor);                
            }            
        }
        
        return visited[node];
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
