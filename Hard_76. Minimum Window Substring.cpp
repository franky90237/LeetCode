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

//2022-06-07
//two pointer
//time  : O(n+m)
//space : O(m)
class Solution {
public:
    string minWindow(string s, string t)
    {
        unordered_map<char,int> dict,record;
        for(auto& c:t) 
        {
            ++dict[c];
            record[c]=0;
        }
        
        int cnt=0;
        int len=s.size()+1;
        int resL=-1;
        int resR=-1;
        int left=0;
        int right=0;
        while(left<=right && right<s.size())
        {
            char c=s[right];
            if(record.find(c)==record.end())
            {
                ++right;
                continue;
            }
            
            ++record[c];
            if(record[c]==dict[c]) ++cnt;
            
            //cout<<right<<endl;
            //print(record);
            while(cnt==dict.size() && left<=right)
            {
                if(len>right-left+1)
                {
                    len=right-left+1;
                    resL=left;
                    resR=right;
                }
                
                if(dict.find(s[left])!=dict.end())
                {
                    --record[s[left]];
                    if(record[s[left]]<dict[s[left]]) --cnt;
                    
                    //cout<<left<<endl;
                    //print(record);
                }
                
                ++left;
            }
                
            ++right;
        }
        
        //cout<<resL<<" "<<resR<<endl;
        return (resL==-1) ? "" : string(s,resL,resR-resL+1);
    }
    
    void print(unordered_map<char,int>& record)
    {
        for(auto& i:record)
        {
            cout<<i.first<<":";
            cout<<i.second<<" ";
            cout<<endl;
        }
        
        cout<<endl;
    }
};
