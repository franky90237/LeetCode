//2022-04-15
class Solution 
{
private:
    vector<int> original;
    vector<int> data;
    
public:
    Solution(vector<int>& nums) 
    {
        original=nums;
        data=nums;
    }
    
    vector<int> reset() 
    {
        //data=original;
        return original;
    }
    
    vector<int> shuffle() 
    {
        int n=data.size();
        
        int index1=rand()%n;
        int index2=rand()%n;
        swap(data[index1],data[index2]);
        
        return data;
    }
};

//2022-04-15
class Solution 
{
private:
    vector<int> original;
    vector<int> data;
    
public:
    Solution(vector<int>& nums) 
    {
        original=nums;
        data=nums;
    }
    
    vector<int> reset() 
    {        
        return original;
    }
    
    vector<int> shuffle() 
    {
        int n=data.size();
        
        for(int i=0; i<n; ++i)
        {
            swap(data[i],data[i+rand()%(n-i)]);
        }
                
        return data;
    }
};
