//2022-04-21
//TLE
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) 
    {
        int n=nums.size();
        
        int res=0;
        for(int i=0; i<n; ++i)
        {
            for(int j=i; j<n; ++j)
            {
                int a=nums[i];
                int b=nums[j];
                
                if(a==b) continue;
                
                res+=hammingDistance(a,b);
            }
        }
        
        return res;
    }
    
    int hammingDistance(int x, int y) 
    {
        int z=x^y;
        
        int number_of_1=0;
        while(z>0)
        {
            ++number_of_1;
            z=z&(z-1);
        }
        
        return number_of_1;
    }
};

//2022-04-21
class Solution {   
public:
    int totalHammingDistance(vector<int>& nums) 
    {        
        int n=nums.size();        
        
        int res=0;        
        for(int bit=0; bit<32; ++bit)
        {
            int number_of_1=0;
            for(int i=0; i<n; ++i)
            {
                number_of_1 += (nums[i]>>bit) & 1;
            }
            
            int number_of_0=n-number_of_1;
            res+=number_of_1*number_of_0;
        }
        
        return res;
    }
};
