//2022-08-01
//time  : O(n)
//space : O(52), 26 lowercase + 26 uppercase
class Solution {
public:
    int longestPalindrome(string s)
    {
        /*
        abccccdd : (a,1) (b,1) (c,4) (d,2)
        "abbbcccccddeeffffffffffghhhiijjjjkkkk"
        */
                        
        unordered_map<char,int> letters;
        for(auto& c:s) ++letters[c];
        
        bool has_odd=false;
        int sum=0;               
        for(auto& i:letters) 
        {
            int cnt=i.second;
            
            if(cnt%2==0) 
            {
                sum+=cnt;                
            }
            else
            {
                has_odd=true;
                sum+=cnt-1;
            }
            //cout<<sum<<" : "<<i.first<<" "<<i.second<<endl;
        }        
        
        return sum+has_odd;
    }
};
