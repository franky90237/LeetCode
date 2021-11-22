class Solution {
public:
    int openLock(vector<string>& deadends, string target) 
    {                
        unordered_set deadends_set(deadends.begin(),deadends.end());
        if(deadends_set.find("0000")!=deadends_set.end()) return -1;
        
        bool visited[10000]={0};
        queue<string> q;
        q.push("0000");
        int turns=0;
        
        while(!q.empty())
        {            
            int size=q.size();            
            for(int i=0;i<size;++i)
            {
                string node=q.front();                
                q.pop();
                //if(deadends_set.find(node)!=deadends_set.end()) continue;                
                if(node==target) return turns;
                
                for(int j=0;j<4;++j)
                {
                    string plus(node); plus[j]=(plus[j]-'0'+1)%10+'0';
                    string minus(node); minus[j]=(minus[j]-'0'-1+10)%10+'0';
                    //cout<<plus<<" "<<minus<<" : ";
                    
                    if(!visited[stoi(plus)] && deadends_set.find(plus)==deadends_set.end()) 
                    {
                        q.push(plus); 
                        visited[stoi(plus)]=true;
                    }
                    if(!visited[stoi(minus)] && deadends_set.find(minus)==deadends_set.end()) 
                    {
                        q.push(minus); 
                        visited[stoi(minus)]=true;
                    }
                    //if(!visited[stoi(plus)]) {q.push(plus); visited[stoi(plus)]=true;}
                    //if(!visited[stoi(minus)]) {q.push(minus); visited[stoi(minus)]=true;}
                }                
            }            
            ++turns;
        }
        
        return -1;
    }    
};
