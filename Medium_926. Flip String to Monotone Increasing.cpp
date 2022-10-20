//2022-10-20
//TLE
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        int ans=INT_MAX;
        int n=s.size();
        for(int zeros=n; zeros>=0; --zeros)
        {
            int flips=calculate(s, zeros);
            if(flips == 0) return 0;
            //cout<<zeros<<" "<<flips<<endl;
            ans=min(ans, flips);
        }
        
        return ans;
    }
    
    int calculate(string& s, int zeros)
    {
        int flips=0;
        int i=0;
        while(i < zeros)
        {
            if(s[i] != '0') ++flips;
            ++i;
        }
        
        while(i< s.size())
        {
            if(s[i] != '1') ++flips;
            ++i;
        }
        
        return flips;
    }
};

//2022-10-20
//time  : O(n)
//space : O(n)
class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        const int n=s.size();
        int diffZeros[n];
        diffZeros[0]=(s[0] != '0') ? 1 : 0;
        for(int i=1; i<n; ++i)
        {
            diffZeros[i]=diffZeros[i-1];
            if(s[i] != '0') ++diffZeros[i];
            //cout<<diffZeros[i]<<" ";
        }
        
        //cout<<endl;
        
        int diffOnes[n];
        diffOnes[n-1]=(s[n-1] != '1') ? 1 : 0;        
        for(int i=n-2; i>=0; --i)
        {
            diffOnes[i]=diffOnes[i+1];
            if(s[i] != '1') ++diffOnes[i];
            //cout<<diffOnes[i]<<" ";
        }
        
        int ans=INT_MAX;        
        for(int i=-1; i<n; ++i)
        {
            //int flips=calculate(s, zeros);
            int diff0=(i == -1) ? 0 : diffZeros[i];
            int diff1=(i+1 == n) ? 0 : diffOnes[i+1];            
            int flips=diff0+diff1;            
            if(flips == 0) return 0;
            //cout<<i<<" "<<diff0<<" "<<diff1<<endl;
            ans=min(ans, flips);
        }
        
        return ans;
    }    
};

//2022-10-20
//time  : O(n)
//space : O(1)
class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        int oneCnt=0;
        int flipCnt=0;
        for(auto& c: s)
        {
            if(c == '1')
            {
                ++oneCnt;
            }
            else
            {
                int flip_c_to_1_cnt = flipCnt+1;
                int flip_all_1_to_0_cnt=oneCnt;
                flipCnt=min(flip_c_to_1_cnt, flip_all_1_to_0_cnt);
            }
        }
        
        return flipCnt;
    }    
};
