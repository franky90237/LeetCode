class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        //return "";
        if(numerator==0) return "0";
        if(numerator==denominator) return "1";
        
        string interger="";
        vector<int> remainder;
        int r;
        
        if((numerator<0)!=(denominator<0)==1) interger="-";
        long a=abs_my(numerator);
        long b=abs_my(denominator);
        
        update(a,b,interger,remainder);
        if(a==0) return interger;
        interger.push_back('.');
        r=remainder.back();
        
        string fraction="";
        do
        {
            cout<<remainder.back()<<endl;
            update(a,b,fraction,remainder);
            r=remainder.back();
            
        } while( (remainder.size()==1 || r!=remainder[0]) && numerator!=0 );
        
        return (numerator==0) ? interger+fraction : interger+"("+fraction+")";
    }
    
    long abs_my(int num)
    {        
        if(num==INT_MIN) return (long)INT_MAX+1;
        return (num<0) ? -num : num;
    }
    
    void update(long& numerator, long denominator, string& res, vector<int>& remainder)
    {
        if(numerator<denominator)
        {
            remainder.push_back(numerator);
            res.push_back('0');
            numerator=numerator*10;
        }
        else
        {
            remainder.push_back(numerator%denominator);
            res+=to_string(numerator/denominator);
            numerator=(long)remainder.back()*10;
        }
    }
};
