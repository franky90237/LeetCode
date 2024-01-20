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

//2024-01-20
//time  : O(n)
//space : O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n=temperatures.size();
        vector<int> res(n);
        res[n-1]=0;
        for(int i=n-2; i>=0; --i)
        {
            if(temperatures[i] < temperatures[i+1]) res[i]=1;
            else
            {
                int len = res[i+1] + 1;
                while(res[i+len] != 0 && temperatures[i] >= temperatures[i+len]) len += res[i+len];
                
                if(temperatures[i] >= temperatures[i+len]) res[i] = 0;
                else res[i] = len;
            }
        }
        
        return res;
    }
};
