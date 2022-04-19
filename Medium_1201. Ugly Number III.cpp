//2022-04-19
//TLE
//time  : O(k), k is the nthUglyNumber
//space : O(1)
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) 
    {
        vector<int> divisor({a,b,c});
        sort(divisor.begin(),divisor.end());
        
        int size=1;
        for(int i=1; i<3; ++i)
        {
            if(divisor[i]!=divisor[i-1]) 
            {
                divisor[size]=divisor[i];
                ++size;
            }
        }
        divisor.resize(size);
                        
        for(int i=size-1; i>0; --i)
        {
            for(int j=i-1; j>=0; --j)
            {
                if(divisor[i]%divisor[j]==0) 
                {
                    divisor.erase(divisor.begin()+i);
                    break;
                }
            }
        }
        
        //for(auto& i:divisor) cout<<i<<" ";
        
        int num=divisor[0];
        while(n!=0)
        {
            for(auto i:divisor)
            {
                if(num%i==0)
                {
                    --n;
                    break;
                }
            }
            
            ++num;
        }
        
        return num-1;
    }
};

//2022-04-19
//TLE
//time  : O(n)
//space : O(1)
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) 
    {
        vector<int> divisor({a,b,c});
        sort(divisor.begin(),divisor.end());
        
        int size=1;
        for(int i=1; i<3; ++i)
        {
            if(divisor[i]!=divisor[i-1]) 
            {
                divisor[size]=divisor[i];
                ++size;
            }
        }
        divisor.resize(size);
                        
        for(int i=size-1; i>0; --i)
        {
            for(int j=i-1; j>=0; --j)
            {
                if(divisor[i]%divisor[j]==0) 
                {
                    divisor.erase(divisor.begin()+i);
                    break;
                }
            }
        }
        
        //for(auto& i:divisor) cout<<i<<" ";
        
        int mul[size];
        for(int i=0 ; i<size; ++i) mul[i]=1;
        
        int num;
        while(n!=0)
        {
            num=divisor[0]*mul[0];
            for(int i=1; i<size; ++i)
            {
                num=min(num,divisor[i]*mul[i]);
            }
            
            for(int i=0; i<size; ++i)
            {
                if(num==divisor[i]*mul[i]) ++mul[i];
            }
            
            --n;
        }
        
        return num;
    }
};

//2022-04-19
//time  : O(log(2*10^(9)))
//space : O(1)
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) 
    {
        if(a==b && b==c) return a*n;
        
        vector<int> divisor({a,b,c});
        sort(divisor.begin(),divisor.end());
        
        int size=1;
        for(int i=1; i<3; ++i)
        {
            if(divisor[i]!=divisor[i-1]) 
            {
                divisor[size]=divisor[i];
                ++size;
            }
        }
        divisor.resize(size);
                        
        for(int i=size-1; i>0; --i)
        {
            for(int j=i-1; j>=0; --j)
            {
                if(divisor[i]%divisor[j]==0) 
                {
                    divisor.erase(divisor.begin()+i);
                    break;
                }
            }
        }
        
        //for(auto& i:divisor) cout<<i<<" ";
        vector<int> lcm({})
        int cnt=0;
        int low=1;
        int high=2000000000;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            cnt=divisible_cnt(divisor,mid);
            
            //cout<<cnt<<" - "<<low<<" "<<mid<<" "<<high<<endl;
            
            if(cnt<=n) low=mid+1;
            else       high=mid;
        }
        
        return high;
    }
    
    int divisible_cnt(vector<int>& divisor, int num)
    {
        int n=divisor.size();        
        int cnt=0;
        if(n==2)
        {        
            cnt+=num/divisor[0];
            cnt+=num/divisor[1];
            
            cnt-=num/divisor[0]/divisor[1];
        }
        else 
        {
            cnt+=num/divisor[0];
            cnt+=num/divisor[1];
            cnt+=num/divisor[2];
            
            cnt-=num/divisor[0]/divisor[1];
            cnt-=num/divisor[0]/divisor[2];
            cnt-=num/divisor[1]/divisor[2];
            
            cnt+=num/divisor[0]/divisor[1]/divisor[2];
        }
        
        return cnt;
    }
};
