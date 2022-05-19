//2022-05-19
//reference : https://leetcode.com/problems/reorganize-string/discuss/232469/Java-No-Sort-O(N)-0ms-beat-100
//time  : O(n)
//space : O(26)
class Solution {
public:
    string reorganizeString(string s)
    {        
        unordered_map<char,int> letter;
        int max_freq=0;
        char max_freq_letter;
        
        for(auto& i:s)
        {
            ++letter[i];
            if(max_freq<letter[i])
            {
                max_freq=letter[i];
                max_freq_letter=i;
            }
        }
        //printf("%c %d \n",max_freq_letter,max_freq);
        
        if(max_freq > 1 + (s.size()-1)/2) return "";
        
        string ans(s.size(),'.');
        
        int i=0;
        while(letter[max_freq_letter]>0)
        {
            ans[i]=max_freq_letter;
            --letter[max_freq_letter];
            
            i+=2;
        }
        //cout<<ans<<endl;
        
        for(auto& it:letter)
        {
            while(it.second>0 && i<s.size())
            {
                ans[i]=it.first;
                --it.second;
                
                i+=2;
            }
            
            if(i>=s.size()) break;
        }
        //cout<<ans<<endl;
        
        i=1;
        for(auto& it:letter)
        {
            while(it.second>0 && i<s.size())
            {
                ans[i]=it.first;
                --it.second;
                
                i+=2;
            }
            
            if(i>=s.size()) break;
        }
                        
        return ans;
    }
};
