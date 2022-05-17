//2022-05-17
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        //avoid "-0"
        if(numerator==0) return "0";
        
        unordered_map<int,int> remainder;
        string interger="";               
        
        if((numerator<0)!=(denominator<0)==1) interger="-";
        
        long a=abs_my(numerator);
        long b=abs_my(denominator);
        
        update(a,b,interger,remainder);
        
        if(a==0) return interger;
        interger.push_back('.');
        
        string fraction="";
        do
        {
            //cout<<a<<endl;
            int repeat=update(a,b,fraction,remainder);
            if(repeat!=-1)
            {
                int index=remainder[repeat];
                fraction.insert(index,"(");
                return interger+fraction+")";
            }
            
        } while(a!=0);                
        
        return interger+fraction;
    }
    
    long abs_my(int num)
    {        
        if(num==INT_MIN) return (long)INT_MAX+1;
        return (num<0) ? -num : num;
    }
    
    int update(long& numerator, long denominator, string& res, unordered_map<int,int>& remainder)
    {
        int r=numerator%denominator;
        long q=numerator/denominator;
        
        if(remainder.find(r)!=remainder.end()) 
        {
            res+=to_string(q);
            return r;
        }
        
        int index=remainder.size();
        remainder[r]=index;
        res+=to_string(q);
        numerator=(long)r*10;
        
        return -1;
    }
};
