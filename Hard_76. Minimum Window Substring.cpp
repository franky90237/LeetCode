//2022-06-07
//time  : O(n+m)
//space : O(m)
class Solution {
public:
    string minWindow(string s, string t)
    {
        unordered_map<char,int> dict;
        for(auto& c:t) ++dict[c];
        
        int cnt=0;
        string res="";
        unordered_map<char,deque<int>> record;
        for(int i=0; i<s.size(); ++i)
        {
            char c=s[i];
            
            if(dict.find(c)==dict.end()) continue;
            
            int c_cnt=dict[c];
            if(record.find(c)==record.end() || record[c].size()<dict[c])
            {
                record[c].push_back(i);
                ++cnt;
            }
            else
            {
                record[c].pop_front();
                record[c].push_back(i);
            }
            
            if(cnt>=t.size()) update(res,record,s);
            
            //cout<<cnt<<endl;
            //print(record);
        }
        
        return res;
    }
    
    void update(string& res, unordered_map<char,deque<int>>& record, string& s)
    {
        int left=record.begin()->second.front();
        int right=record.begin()->second.back();
        
        for(auto& i:record)
        {
            left=min(left,i.second.front());
            right=max(right,i.second.back());
        }
        
        if(res.size()==0 || res.size()>right-left+1)
        {
            res=string(s,left,right-left+1);
        }
    }
    
    void print(unordered_map<char,deque<int>>& record)
    {
        for(auto& i:record)
        {
            cout<<i.first<<":";
            deque tmp=i.second;
            while(!tmp.empty())
            {
                cout<<tmp.front()<<" ";
                tmp.pop_front();
            }
            cout<<endl;
        }
        
        cout<<endl;
    }
};
