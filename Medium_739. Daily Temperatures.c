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
    
    //monotonic stack (begin to end)
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int size=temperatures.size();
        vector<int> result(size,0);
        stack<int> temperatures_index;
        
        for(int curr=0;curr<size;++curr)
        {
            while(!temperatures_index.empty() && temperatures[curr]>temperatures[temperatures_index.top()])
            {
                int index=temperatures_index.top();
                temperatures_index.pop();
                
                result[index]=curr-index;
            }
            temperatures_index.push(curr);
        }
        
        return result;
    }
    
    //monotonic stack (end to begin)
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int size=temperatures.size();
        vector<int> result(size,0);
        stack<int> temperatures_index;
        
        for(int curr=size-1;curr>=0;--curr)
        {
            while(!temperatures_index.empty() && temperatures[curr]>=temperatures[temperatures_index.top()])
            {                
                temperatures_index.pop();                                
            }
            
            if(!temperatures_index.empty()) result[curr]= temperatures_index.top()-curr;
            
            temperatures_index.push(curr);
        }
        
        return result;
    }    
};
