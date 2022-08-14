//2022-08-14
//MLE
//time  : O(n*m), m is the digit size of n
//space : O(n)
class Solution {
public:
    int countSpecialNumbers(int n)
    {
        bool special[n+1];
        for(long i=0; i<=n; ++i) special[i]=true;        
        
        long ans=n;
        
        for(long i=1; i<=n; ++i)
        {
            //cout<<i<<" ";
            
            int digit[10]={0};
            long num=i;
            while(num!=0)
            {
                int q=num/10;
                int r=num%10;
                
                if(!special[q] || digit[r]==1) 
                {
                    special[i]=false;
                    --ans;
                    break;
                }
                
                ++digit[r];
                num=q;
            }           
        }
        
        return ans;
    }
};

//2022-08-14
//TLE
//time  : O(n*m), m is the digit size of n
//space : O(n)
class Solution {
public:
    int countSpecialNumbers(int n)
    {
        unordered_set<int> not_special;              
        
        int ans=n;
        
        for(int i=1; i<=n; ++i)
        {
            //cout<<i<<" ";
            
            int digit[10]={0};
            int num=i;
            while(num!=0)
            {
                int q=num/10;
                int r=num%10;
                
                if(not_special.count(q) || digit[r]==1) 
                {
                    not_special.insert(i);
                    --ans;
                    break;
                }
                
                ++digit[r];
                num=q;
            }                         
        }
        
        return ans;
    }
};

//2022-08-14
//backtracking
//time  : O(9^m), m is the digit size of n
//space : O(m)
class Solution {
public:
    int countSpecialNumbers(int n)
    {        
        int ans=0;
        
        for(int i=1; i<=9; ++i)
        {           
            bool digit[10]={false};
            digit[i]=true;
            
            dfs(i,n,digit,ans);
            //cout<<i<<" : "<<ans<<endl;
            
            digit[i]=false;
        }
        
        return ans;
    }
    
    void dfs(long cur, int n, bool digit[], int& ans)
    {
        if(cur>n) return;
        
        ++ans;
        
        if(cur*10 > n) return;
        
        for(int i=0; i<=9; ++i)
        {
            if(digit[i]) continue;            
            digit[i]=true;
            
            dfs(cur*10+i,n,digit,ans);            
            
            digit[i]=false;            
            if(cur*10+i>n) break;
        }                
    }
};
