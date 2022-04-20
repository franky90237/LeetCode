//2022-04-20
//backtracking
class Solution {
public:
    bool checkPowersOfThree(int n) 
    {
        unordered_map<int,int> p3;
        return solve(p3,0,0,n);
    }
    
    bool solve(unordered_map<int,int>& p3, int now, int num, int target)
    {
        //cout<<now<<" "<<num<<endl;
        if(num==target) return true;
        if(num>target) return false;
        
        int i=now;
        do
        {
            if(p3.find(i)==p3.end())
            {
                long tmp=pow(3,i);
                if(tmp>target) return false;
                p3[i]=tmp;
            }
            
            num+=p3[i];
            bool flag=solve(p3,i+1,num,target);
            if(flag) return true;
            num-=p3[i];
            
            ++i;
        }while(num<=target);
        
        return false;
    }
};
