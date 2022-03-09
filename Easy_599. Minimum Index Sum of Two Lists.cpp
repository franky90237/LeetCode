//time  : O(n+m)
//space : O(n+m)
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        unordered_map<string,int> m1;
        for(int i=0; i<list1.size(); ++i) m1[list1[i]]=i;
        
        unordered_map<string,int> m2;
        int min=INT_MAX;
        for(int i=0; i<list2.size(); ++i)
        {
            if(m1.find(list2[i])!=m1.end()) 
            {
                int sum=i+m1[list2[i]];
                m2[list2[i]]=sum;
                if(min>sum) min=sum;
            }
        }
        
        vector<string> res;
        for(auto& i:m2)
        {
            if(i.second==min) res.push_back(i.first);
        }
        
        return res;
    }
};
