//2023-01-18
//time  : O(n)
//space : O(n)
class Solution {
public:
    long long countGood(vector<int>& nums, int k)
    {
        /*
         0 1 2 3 4 5 6 7 8 9 0 1 2 3
        [2,3,1,3,2,3,3,3,1,1,3,2,2,2]
        18

        l=0, r=1, p=0
        l=0, r=2, p=0
        l=0, r=3, p=0
        l=0, r=4, p=2  [1:1] [2:2] [3:2]
        l=0, r=5, p=4  [1:1] [2:2] [3:3]
        l=0, r=6, p=7  [1:1] [2:2] [3:4]
        l=0, r=7, p=11 [1:1] [2:2] [3:5]
        l=0, r=8, p=12 [1:2] [2:2] [3:5]
        l=0, r=9, p=14 [1:3] [2:2] [3:5]
        l=0, r=10, p=19 [1:3] [2:2] [3:6] a=3
        l=1, r=10, p=18 [1:3] [2:1] [3:6] a=6
        l=2, r=10, p=13 [1:3] [2:1] [3:5] a=6
        l=2, r=11, p=14 [1:3] [2:2] [3:5] a=6
        l=2, r=12, p=16 [1:3] [2:3] [3:5] a=6
        l=2, r=13, p=19 [1:3] [2:4] [3:5] a=9

        */
        
        int n=nums.size();
        int l=0;
        int r=0;
        unordered_map<int, int> table;
        long long pairs=0;
        long long ans=0;
        
        while(r < n)
        {
            ++table[nums[r]];
            
            if(table[nums[r]] >= 2)
            {
                int cnt = table[nums[r]];
                int pre_num_pairs = (cnt-1) * (cnt-2) / 2;
                int cur_num_pairs = cnt * (cnt-1) / 2;                
                pairs = pairs - pre_num_pairs + cur_num_pairs;
                //cout<<l<<" "<<r<<" "<<pairs<<endl;
                                
                while(pairs >= k)
                {
                    ans += n-r;

                    --table[nums[l]];

                    /*if(table[nums[l]] == 0)
                    {
                        table.erase(nums[l]);                            
                    }*/
                    if(table[nums[l]] >= 1)
                    {
                        cnt = table[nums[l]];
                        pre_num_pairs = cnt * (cnt + 1) /2;
                        cur_num_pairs = cnt * (cnt - 1) /2;
                        pairs = pairs - pre_num_pairs + cur_num_pairs;
                    }

                    ++l;
                }            
                
                //cout<<l<<" "<<r<<" "<<pairs<<endl<<endl;
            }
                                    
            ++r;
        }
        
        return ans;
    }
};

//2023-01-18
//time  : O(n)
//space : O(n)
class Solution {
public:
    long long countGood(vector<int>& nums, int k)
    {        
        /*
        1
        3 = 1+2
        6 = 1+2+3
        10 = 1+2+3+4
        15 = 1+2+3+4+5
        21 = 1+2+3+4+5+6

        C(n, 2) = n-1 + C(n-1, 2)

        n*(n-1) /2 = n-1 + (n-1)*(n-2)/2;
        n*(n-1) = 2n-2 + (n-1)*(n-2)
        n*n-n=n*n-3n+2+2n-2 

        n*n-n | n*n-3n+2 + 2x

        2x = 2n-2
        x = n-1
        */
        
        int n=nums.size();
        int l=0;
        int r=0;
        unordered_map<int, int> table;
        long long pairs=0;
        long long ans=0;
        
        while(r < n)
        {
            ++table[nums[r]];
            pairs += table[nums[r]]-1;
            
            while(pairs >= k)
            {
                ans += n-r;
                --table[nums[l]];
                pairs -= table[nums[l]];
                
                ++l;
            }
            
            ++r;
        }
        
        return ans;
    }
};
