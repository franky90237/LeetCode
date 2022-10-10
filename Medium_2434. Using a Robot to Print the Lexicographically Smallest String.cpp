//2022-10-09
//time  : O(n)
//space : O(n)
class Solution {
public:
    string robotWithString(string s) 
    {
        int n=s.size();         
        
        map<char, int> table;
        for(int i=0; i<n; ++i)
        {            
            ++table[s[i]];
        }
                
        string paper;
        string t;
        for(int i=0; i<n; ++i)
        {
            char c=s[i];
            t.push_back(c);
            --table[c];
            if(table[c]==0) table.erase(c);
            
            while(!t.empty() && smallest(table, t.back()))
            {
                //cout<<t.back()<<" "<<t<<endl;
                paper.push_back(t.back());
                t.pop_back();                
            }
            
            /*cout<<t<<" : "<<paper<<endl;
            for(auto& it: table) cout<<"("<<it.first<<", "<<it.second<<") ";
            cout<<endl;*/
        }
        
        while(!t.empty())
        {
            paper.push_back(t.back());
            t.pop_back();          
        }
                        
        return paper;
    }
    
    bool smallest(map<char, int>& table, char c)
    {    
        if(table.begin()->first >= c) return true;
        return false;
    }
};

//2022-10-10
//time  : O(n)
//space : O(n)
class Solution {
public:
    string robotWithString(string s) 
    {
        int n=s.size();         
        
        int freq[26]={0};
        for(auto& c: s) ++freq[c-'a'];
        
        int smallest=0;
        string paper;
        string t;
        for(int i=0; i<n; ++i)
        {
            char c=s[i];
            t.push_back(c);
            --freq[c-'a'];         
            
            while(smallest < 26 && freq[smallest] == 0) ++smallest;
            
            while(!t.empty() && t.back() <= (smallest+'a'))
            {
                //cout<<t.back()<<" "<<t<<endl;
                paper.push_back(t.back());
                t.pop_back();                
            }
            
            /*cout<<t<<" : "<<paper<<endl;
            for(auto& it: table) cout<<"("<<it.first<<", "<<it.second<<") ";
            cout<<endl;*/
        }
        
        while(!t.empty())
        {
            paper.push_back(t.back());
            t.pop_back();          
        }
                        
        return paper;
    }    
};
