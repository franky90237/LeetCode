//2022-10-15
//time  : O(n)
//space : O(1)
class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int n=chars.size();
        
        int push=0;
        int begin=0;
        while(begin < n)
        {
            int end=begin;            
            while(end < n && chars[end] == chars[begin])
            {
                ++end;
            }
                    
            chars[push]=chars[begin];
            ++push;
            
            int cnt=end-begin;
            //cout<<chars[begin]<<" | "<<cnt<<" "<<endl;
            if(cnt != 1)
            {
                int digit=(float)log(cnt)/(float)log(10);                
                int powerOf10=pow(10, digit);                
                while(powerOf10 != 0)
                {
                    int q=cnt/powerOf10;
                    chars[push]=q+'0';
                    ++push;
                    
                    cnt%=powerOf10;
                    powerOf10/=10;
                }                                
            }
            
            //cout<<endl;            
            begin=end;
        }
        
        //cout<<push<<endl;
        return push;
    }
};

//2022-11-03
//time  : O(n*n), n is the bank size
//spcae : O(n)
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if(bankSet.count(end) == 0) return -1;
        
        unordered_set<string> visited;
        queue<string> q;
        
        int ans=0;
        visited.insert(start);
        q.push(start);
        while(!q.empty())
        {
            int size=q.size();
            while(size > 0)
            {
                string cur=q.front();
                q.pop();
                if(cur == end) return ans;
                
                for(auto& gene: bankSet)
                {
                    if(visited.count(gene) == 0 && difference(cur, gene) == 1)
                    {
                        visited.insert(gene);
                        q.push(gene);
                    }
                }
                
                --size;
            }
            
            ++ans;
        }
                        
        return -1;
    }    
    
    int difference(const string& a, const string& b)
    {
        int diff=0;
        for(int i=0; i<a.size(); ++i)
        {
            if(a[i] != b[i])
            {
                ++diff;
                if(diff >= 2) break;
            }
        }
        
        return diff;
    }        
};

//2022-11-03
//time  : O(n*n), n is the bank size
//spcae : O(n)
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if(bankSet.count(end) == 0) return -1;
        
        unordered_set<string> visited;
        queue<string> q;
        
        int ans=0;
        visited.insert(start);
        q.push(start);
        while(!q.empty())
        {
            int size=q.size();
            while(size > 0)
            {
                string cur=q.front();
                q.pop();
                if(cur == end) return ans;
                                               
                for(int i=0; i<cur.size(); ++i)
                {                    
                    char original=cur[i];
                    
                    for(char c: "ATCG")
                    {                        
                        cur[i]=c;
                        if(visited.count(cur) == 0 && bankSet.count(cur) > 0)
                        {
                            visited.insert(cur);
                            q.push(cur);
                        }
                    }
                    
                    cur[i]=original;
                }                
                
                --size;
            }
            
            ++ans;
        }
                        
        return -1;
    }              
};
