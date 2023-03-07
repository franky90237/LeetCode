//2023-03-07
//time  : O(n*k)
//space : O(n)
class Solution 
{
private:
    unordered_map<int, vector<int>> record;
    
public:
    int findValidSplit(vector<int>& nums)
    {        
        unordered_set<int> left;
        unordered_map<int, int> right;
        
        for(auto num: nums)
        {
            vector<int> factor=factorize(num);
            for(auto prime: factor)
            {
                ++right[prime];
            }
        }
        
        //print(right);
        
        int n=nums.size();
        for(int i=0; i<n-1; ++i)
        {
            vector<int> factor=factorize(nums[i]);
            for(auto prime: factor)
            {
                left.insert(prime);
                --right[prime];
                if(right[prime] == 0)
                {
                    left.erase(prime);
                }                                
            }
            
            //print(right);
            if(left.empty())
            {
                return i;
            }
        }
        
        return -1;
    }
    
    vector<int> factorize(int num)
    {
        if(record.find(num) != record.end())
        {
            return record[num];
        }
        
        int original_num=num;
        vector<int> res;
        for(int i=2; num >= i && i<=1000; ++i)
        {
            if(num % i == 0)
            {
                res.push_back(i);
                
                do
                {
                    num /= i;
                } while(num % i == 0);
            }
        }
        
        if(num > 1)
        {
            res.push_back(num);
        }
        
        record[original_num]=res;
        return res;
    }
    
    void print(unordered_map<int, int>& right)
    {
        for(auto& it: right)
        {
            cout<<"("<<it.first<<","<<it.second<<") ";
        }
        cout<<endl;
    }
};
