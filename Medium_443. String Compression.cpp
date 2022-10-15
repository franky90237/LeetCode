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
