//2022-09-28
class Solution {
public:
    bool isMatch(string s, string p) 
    {
        /*

        "abbbbbbbbbbbbc"
        "a***b.*.*.*.b*"
        "ab"
        ".*c"
        "a"
        ".*..a*"

        "abcaaaaaaabaabcabac"
        ".*ab.a.*a*a*.*b*b*"

        abca   aaaaaabaabcabac
        .*ab.a .*a*a*.*b*b*

        abca   aaaaaa  baabcabac
        .*ab.a .*a*a*  .*         b*b*
        */        
        
        int push=1;
        for(int i=1; i<p.size(); ++i)
        {
            p[push]=p[i];
            
            if(p[i] == '*')
            {            
                while(i < p.size() && p[i] == '*') ++i;
                --i;
            }
            
            ++push;
        }
        
        p.resize(push);
        //cout<<p<<endl;
                        
        return solve(s, p, 0, 0);
    }
    
    bool solve(string& s, string& p, int si, int pi)
    {
        //cout<<si<<" "<<pi<<endl;
        
        if(si >= s.size() && pi >= p.size()) return true;
        if(si < s.size() && pi >= p.size()) return false;
        if(si >= s.size() && pi < p.size())
        {
            int cnt=p.size()-pi;
            if(cnt%2==1) return false;
            
            ++pi;
            while(pi < p.size())
            {
                if(p[pi] != '*') return false;
                pi+=2;
            }
            
            return true;
        }
        
        //cout<<si<<" "<<pi<<" | "<<s[si]<<" "<<p[pi]<<endl;
        
        if(p[pi] == '.')
        {
            if(pi == p.size()-1) return solve(s, p, si+1, pi+1);
            
            if(p[pi+1] == '*')
            {
                bool flag=solve(s, p, si, pi+2);
                if(flag) return true;
                             
                for(int i=si; i < s.size(); ++i)
                {
                    flag=solve(s, p, i+1, pi+2);
                    if(flag) return true;
                }
                
                return flag;
            }
            else
            {
                return solve(s, p, si+1, pi+1);
            }
        }
        else
        {
            /*if(p[pi] == '*')
            {
                cout<<"error : p[pi] == '*'"<<endl;                
            }*/
            
            if(pi == p.size()-1) 
            {
                if(s[si] != p[pi]) return false;
                return solve(s, p, si+1, pi+1);
            }
            
            if(p[pi+1] == '*')
            {
                bool flag=solve(s, p, si, pi+2);
                if(flag) return true;
                
                for(int i=si; i < s.size() && s[i] == p[pi]; ++i)
                {
                    flag=solve(s, p, i+1, pi+2);
                    if(flag) return true;
                }
                
                return flag;
            }
            else
            {
                if(s[si] != p[pi]) return false;                
                return solve(s, p, si+1, pi+1);
            }
        }
    }
};
