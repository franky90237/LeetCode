//2022-10-18
//time  : O(n)
//sapce : O(1)
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) 
    {
        unordered_set<int> table;
        for(auto& num: nums)
        {
            table.insert(num);
            table.insert(reverse_int(num));
        }
        
        return table.size();
    }
    
    int reverse_int(int num)
    {
        int res=0;
        while(num != 0)
        {
            res = res*10 + num%10;
            num /= 10;
        }
        
        return res;
    }
};
