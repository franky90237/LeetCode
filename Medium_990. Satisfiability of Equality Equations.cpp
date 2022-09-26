//2022-09-26
//time  : O(n)
//space : O(26)
class union_find
{
private:
    vector<int> parent;
    vector<int> size;
    
public:
    union_find(int n)
    {
        for(int i=0; i<n; ++i)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    
    void combine(int a, int b)
    {
        int root_a=find(a);
        int root_b=find(b);        
        if(a==b) return;
        
        if(size[root_a] > size[root_b])
        {
            parent[root_b]=root_a;
            size[root_a]+=size[root_b];
        }
        else
        {
            parent[root_a]=root_b;
            size[root_b]+=size[root_a];
        }
    }
    
    int find(int a)
    {
        if(parent[a] == a) return a;
        
        parent[a]=find(parent[a]);
        return parent[a];
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations)
    {        
        union_find uf(26);
        for(auto& equation : equations)
        {
            if(equation[1] == '!') 
            {
                if(equation[0] == equation[3]) return false;
                continue;
            }
            //cout<<equation<<endl;
            
            char var1=equation[0];
            char var2=equation[3];            
            uf.combine(var1-'a', var2-'a');
        }
        
        //cout<<"----------------"<<endl;
        
        for(auto& equation : equations)
        {
            if(equation[1] == '=') continue;
            //cout<<equation<<endl;
            
            char var1=equation[0];
            char var2=equation[3];
            int p1=uf.find(var1-'a');
            int p2=uf.find(var2-'a');
            
            if(p1==p2) return false;
        }   
        
        return true;
    }
};
