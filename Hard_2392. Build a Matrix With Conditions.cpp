//2022-08-29
//topogical sort
//time  : O(k+e), e is the number of edges in the graph
//space : O(k)
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions)
    {
        //row
        vector<vector<int>> graph_row(k+1,vector<int>());
        vector<int> in_degree_row(k+1,0);
        build_graph(graph_row,in_degree_row,rowConditions);
        
        vector<int> topo_row;
        if(!topological_sort(k,graph_row,in_degree_row,topo_row)) return {};
        
        //column
        vector<vector<int>> graph_col(k+1,vector<int>());
        vector<int> in_degree_col(k+1,0);
        build_graph(graph_col,in_degree_col,colConditions);        
        
        vector<int> topo_col;
        if(!topological_sort(k,graph_col,in_degree_col,topo_col)) return {};        
        
        int mapping_row[k+1];
        for(int row=0; row<topo_row.size(); ++row)
        {
            int node=topo_row[row];
            mapping_row[node]=row;
        }
        
        vector<vector<int>> ans(k,vector<int>(k,0));
        for(int col=0; col<topo_col.size(); ++col)
        {
            int node=topo_col[col];
            int row=mapping_row[node];
            ans[row][col]=node;
        }
        
        return ans;
    }
    
    void build_graph(vector<vector<int>>& graph, vector<int>& in_degree, vector<vector<int>>& input)
    {
        for(int i=0; i<input.size(); ++i)
        {
            graph[input[i][0]].push_back(input[i][1]);
            ++in_degree[input[i][1]];
        }
    }
    
    bool topological_sort(int k, vector<vector<int>>& graph, vector<int>& in_degree, vector<int>& topo)
    {
        queue<int> q;
        for(int i=1; i<=k; ++i)
        {
            if(in_degree[i]==0) q.push(i);
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto& neighbor:graph[node])
            {
                --in_degree[neighbor];
                if(in_degree[neighbor]==0) q.push(neighbor);
            }
        }
        
        /*for(auto& i:topo) cout<<i<<" ";
        cout<<endl;*/
        return topo.size()==k;
    }
};
