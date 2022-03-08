class Solution {
public:
    bool isHappy(int n) 
    {
        if(n==1) return true;
        
        unordered_set<int> s;
        int sum=0;
        
        s.insert(n);
        while(sum!=1)
        {
            sum=0;            
            while(n!=0)
            {
                int r=n%10;
                sum=sum+r*r;
                n=n/10;
            }
            
            //cout<<sum<<endl;
            if(s.count(sum)>0) return false;
            
            s.insert(sum);
            n=sum;
        }
        
        return true;
    }
};

class Solution {
public:
    bool isHappy(int n) 
    {
        if(n==1) return true;
        
        int slow=n,fast=n;
        
        while(n!=1)
        {
            slow=nextNumber(slow);
            fast=nextNumber(fast);
            fast=nextNumber(fast);
            
            n=fast;
            if(fast==slow) break;
        }
        
        return n==1;
    }
    
    int nextNumber(int n)
    {
        int sum=0;          
        while(n!=0)
        {
            int r=n%10;
            sum=sum+r*r;
            n=n/10;
        }
        
        return sum;
    }
};
