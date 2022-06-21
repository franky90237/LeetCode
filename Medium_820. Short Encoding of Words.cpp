//2022-06-21
//time  : O(n*m), m is the average number of word length
//space : O(n*m)
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words)
    {
        unordered_set<string> s;
        for(auto word:words) s.insert(word);
        
        auto it=s.begin();
        while(it!=s.end())
        {
            for(int i=1; i<it->size(); ++i)
            {
                string sub=it->substr(i);
                if(s.count(sub)!=0) s.erase(sub);
            }
            
            ++it;            
        }
        
        int sum=0;
        for(auto& i:s) 
        {
            sum+=i.size()+1;
            //cout<<i<<endl;
        }
        
        return sum;
    }
};
