class Solution {
public:
    int numJewelsInStones(string jewels, string stones) 
    {
        unordered_set<char> s;
        for(auto& i:jewels) s.insert(i);
        
        int cnt=0;
        for(auto& i:stones)
        {
            if(s.count(i)!=0) ++cnt;
        }
        
        return cnt;
    }
};
