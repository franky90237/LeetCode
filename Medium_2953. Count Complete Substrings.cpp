//2023-12-03
//time  : O(n*26*26)
//space : O(26)
class Solution {
public:
    int countCompleteSubstrings(string word, int k) 
    {
        int n=word.size();
        
        int ans=0;
        for(int len=k; len<=26*k && len<=n; len+=k)
        {
            ans += getCnt(word, len, k);
            //cout<<len<<" "<<ans<<endl;
        }
        
        return ans;
    }
    
    int getCnt(string& s, int len, int k)
    {
        //cout<<len<<" : "<<endl;
        int n=s.size();
        vector<int> letters(26, 0);
        
        int cnt=0; 
        int left=0;
        for(int right=0; right<n; ++right)
        {
            //cout<<left<<" "<<right<<endl;
            if(right-left >= len) 
            {
                --letters[s[left]-'a'];
                ++left;
            }
                                                
            if(right > 0 && abs(s[right]-s[right-1]) > 2)
            {
                left=right;
                fill(letters.begin(), letters.end(), 0);
            }
            
            ++letters[s[right]-'a'];
            
            if(right-left+1 >= len && letters[s[right]-'a'] == k && letters[s[left]-'a'] == k && valid(letters, k))
            {
                //cout<<len<<" : "<<left<<" "<<right<<endl;
                ++cnt;
            }
        }
        
        return cnt;
    }
    
    
    bool valid(vector<int>& letters, int k)
    {        
        for(int i=0; i<26; ++i)
        {
            if(letters[i] == 0) continue;
            if(letters[i] != k) return false;            
        }
        
        return true;
    }
};
