//recursive : like DFS + backtracking
class Solution 
{
private:
    string table[10];
    
public:
    vector<string> letterCombinations(string digits) 
    {
        if(digits.size()==0) return {};
        
        config();
        
        vector<string> res;
        string tmp;
        solve(res,tmp,digits,0);
        
        return res;
    }
    
    void solve(vector<string>& res, string& tmp, string& digits, int now)
    {
        int n=digits.size();
        
        if(now==n)
        {
            //cout<<tmp<<endl;
            res.push_back(tmp);
            return;
        }
        
        int num=digits[now]-'0';
        for(auto& s:table[num])
        {
            tmp.push_back(s);
            solve(res,tmp,digits,now+1);
            tmp.pop_back();
        }
    }
    
    void config()
    {
        table[2]="abc";
        table[3]="def";
        table[4]="ghi";
        table[5]="jkl";
        table[6]="mno";
        table[7]="pqrs";
        table[8]="tuv";
        table[9]="wxyz";
    }
};

//iterative : like BFS
class Solution 
{
private:
    string table[10];
    
public:
    vector<string> letterCombinations(string digits) 
    {
        if(digits.size()==0) return {};
        
        config();
        
        vector<string> res;
        res.push_back("");
        for(int i=0; i<digits.size(); ++i)
        {
            int num=digits[i]-'0';
            vector<string> new_res;
            for(auto& candidate:res)
            {                
                for(auto& s:table[num])
                {
                    new_res.push_back(candidate+s);
                }
            }
            
            swap(res,new_res);
        }
        
        return res;
    }
    
    void config()
    {
        table[2]="abc";
        table[3]="def";
        table[4]="ghi";
        table[5]="jkl";
        table[6]="mno";
        table[7]="pqrs";
        table[8]="tuv";
        table[9]="wxyz";
    }
};
