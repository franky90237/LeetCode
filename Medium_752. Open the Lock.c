class Solution {
public:
    //BFS
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
    
    //Bidirectional BFS
    int openLock(vector<string>& deadends, string target) 
    {                
        unordered_set deadends_set(deadends.begin(),deadends.end());
        if(deadends_set.find("0000")!=deadends_set.end()) return -1;
        
        /*bool *s_visited=new bool[10000];
        bool *t_visited=new bool[10000];
        memset(s_visited,false,10000);
        memset(t_visited,false,10000);*/
        unordered_set<string> visited;
        unordered_set<string> *source_set=new unordered_set<string>();
        unordered_set<string> *target_set=new unordered_set<string>();
        source_set->insert("0000");
        target_set->insert(target);
        //s_visited[0]=true;
        //t_visited[stoi(target)]=true;
        int turns=0;
        
        while(!source_set->empty() && !target_set->empty())
        {
            unordered_set<string> *temp_set=new unordered_set<string>();
            int size=source_set->size();
            //cout<<size<<endl;
            
            for(int i=0;i<size;++i)
            {           
                string node=*(source_set->begin());                
                source_set->erase(source_set->begin());
                visited.insert(node);
                //s_visited[stoi(node)]=true;
                //if(deadends_set.find(node)!=deadends_set.end()) continue;                
                //if(node==target) return turns;
                
                if(target_set->find(node)!=target_set->end())
                {
                    //cout<<endl<<source_set->size()<<" "<<target_set->size()<<endl;
                    //print_set(*source_set); print_set(*target_set); 
                    //cout<<endl<<node;
                    delete source_set;
                    delete target_set;                    
                    return turns;
                }
                
                for(int j=0;j<4;++j)
                {
                    string plus(node); plus[j]=(plus[j]-'0'+1)%10+'0';
                    string minus(node); minus[j]=(minus[j]-'0'-1+10)%10+'0';
                    //cout<<plus<<" "<<minus<<" : ";
                    
                    if(visited.find(plus)==visited.end() && deadends_set.find(plus)==deadends_set.end()) 
                    {
                        temp_set->insert(plus); 
                        //s_visited[stoi(plus)]=true;
                    }
                    if(visited.find(minus)==visited.end() && deadends_set.find(minus)==deadends_set.end()) 
                    {
                        temp_set->insert(minus);
                        //s_visited[stoi(minus)]=true;
                    }                   
                }                                
            }
            //cout<<endl;
            
            /*unordered_set<string> *deleted_set=source_set;
            source_set=temp_set;            
            delete deleted_set;*/
            
            unordered_set<string> *deleted_set=source_set;
            source_set=target_set;
            target_set=temp_set;
            delete deleted_set;
            
            /*bool *temp_array=s_visited;
            s_visited=t_visited;
            t_visited=temp_array;*/
            
            ++turns;         
        }
        
        delete source_set;
        delete target_set;
        return -1;
    }
    
    /*void print_set(unordered_set<string>& p)
    {
        cout<<endl;
        for(auto it=p.begin();it!=p.end();++it)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }*/    
};
