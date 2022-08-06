//2022-08-07
//math
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int times=minutesToTest/minutesToDie;
        return ceil(log(buckets)/log(times+1));
    }
};
