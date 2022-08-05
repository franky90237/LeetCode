//2022-08-05
//math, pattern
class Solution {
public:
    int mirrorReflection(int p, int q)
    {
        int lcm=least_common_multiple(p,q);
        
        int m=lcm/p;
        int n=lcm/q;
        
        if(m%2==0) return 0;           //the last was the flipped room
        if(m%2==1 && n%2==1) return 1; //the last was the original room and the laser ray finished in the right side
        if(m%2==1 && n%2==0) return 2; //the last was the original room and the laser ray finished in the left side
        
        //dummy return
        return -1;
    }
    
    int least_common_multiple(int p, int q)
    {
        int gcd=greatest_common_divisor(p,q);
        return p*q/gcd;
    }
    
    int greatest_common_divisor(int p, int q)
    {
        /*
        gcd(16,12)=gcd(12,4)=gcd(4,0)
        gcd(5,4)=gcd(4,1)=gcd(1,0)
        */
        
        while(q!=0)
        {
            int tmp=p;
            p=q;
            q=tmp%q;
        }
        
        return p;
    }
};

//2022-08-05
//math
class Solution {
public:
    int mirrorReflection(int p, int q)
    {        
        int m=1;
        int n=1;
        while(m*p != n*q)
        {
            ++n;
            m=n*q/p;
            //cout<<m<<" "<<n<<endl;
        }
        
        if(m%2==0) return 0;           //the last was the flipped room
        if(m%2==1 && n%2==1) return 1; //the last was the original room and the laser ray finished in the right side
        if(m%2==1 && n%2==0) return 2; //the last was the original room and the laser ray finished in the left side
        
        //dummy return
        return -1;
    }    
};
