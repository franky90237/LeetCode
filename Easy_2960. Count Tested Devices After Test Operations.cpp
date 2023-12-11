//2023-12-11
//time  : O(n)
//space : O(1)
class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) 
    {
        int ans=0;
        int decrease=0;
        for(int val: batteryPercentages)
        {
            if(val-decrease > 0)
            {
                ++decrease;
                ++ans;
            }
        }
        
        return ans;
    }
};
