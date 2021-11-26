class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int size=temperatures.size();
        vector<int> result(size,0);
        
        for(int i=size-2;i>=0;--i)
        {
            int j=i+1;
            while(j<size)
            {
                if(temperatures[j]>temperatures[i])
                {
                    result[i]=j-i;
                    break;
                }
                else
                {
                    if(result[j]==0) break;
                    
                    j=j+result[j];                    
                }
            }
        }
        
        return result;
    }
};
