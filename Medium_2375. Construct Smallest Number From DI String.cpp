//2022-08-17
//time  : O(n!)
//space : O(1)
class Solution {
public:
    string smallestNumber(string pattern)
    {
        /*
        I I I I D
        1 2 3 4 5 6                        
        */
        
        int n=pattern.size();
        
        string ans;
        for(int i=1; i<=n+1; ++i)
        {
            ans.push_back(i+'0');
        }
        //cout<<ans<<endl;
        
        while(true)
        {
            bool is_find=true;
            
            for(int i=0; i<n; ++i)
            {
                if(!match(i,pattern,ans)) 
                {
                    is_find=false;
                    break;
                }
            }
            
            if(is_find) break;            
            next_permutation(ans.begin(),ans.end());
        }
                
        return ans;
    }
    
    bool match(int cur, string& pattern, string ans)
    {
        if(pattern[cur]=='I' && ans[cur]<ans[cur+1]) return true;
        else if(pattern[cur]=='D' && ans[cur]>ans[cur+1]) return true;
        return false;
    }
};

//2022-08-17
//time  : O(n)
//space : O(1)
class Solution {
public:
    string smallestNumber(string pattern)
    {
        int n=pattern.size();
        
        string ans;
        for(int i=1; i<=n+1; ++i)
        {
            ans.push_back(i+'0');
        }
        //cout<<ans<<endl;
        
        int start=0;
        for(int i=0; i<n; ++i)
        {
            if(pattern[i]=='I')
            {
                //cout<<start<<" "<<i<<endl;
                reverse(ans.begin()+start,ans.begin()+i+1);
                start=i+1;
            }
        }
        
        reverse(ans.begin()+start,ans.end());
                
        return ans;
    }      
};
