//2022-06-30
//time  : O(n)
//space : O(26)
class Solution {
public:
    int minDeletions(string s)
    {        
        int char_cnt[26]={0};
        for(auto& c:s) ++char_cnt[c-'a'];
        
        map<int,int> frequency;
        frequency[0]=0;
        for(auto& i:char_cnt)
        {
            if(i!=0) ++frequency[i];
        }
        
        /*int n=s.size();
        int cnt=1;
        for(int i=1; i<n; ++i)
        {
            if(s[i-1]!=s[i])
            {
                ++frequency[cnt];
                cnt=1;
            }
            else
            {
                ++cnt;
            }
        }*/
                
        //++frequency[cnt];
        //if(frequency.find(1)==frequency.end()) frequency[1]=0;        
        
        //print(frequency);
        
        int res=0;
        auto it1=frequency.rbegin();
        auto it2=frequency.rbegin();
        ++it2;
        
        for(; it2!=frequency.rend(); ++it1, ++it2)
        {
            if(it1->second!=1) 
            {
                int increment=update(res,it1,it2);
                it2->second+=increment;
                //print(frequency);
            }
        }               
        
        return res;
    }
    
    int update(int& res, map<int,int>::reverse_iterator  it1, map<int,int>::reverse_iterator  it2)
    {
        //9:7  diff=2  6:6-2    = 6:4
        //9:12 diff=-3 6:6-(-3) = 6:9
        
        //9:2  diff=7  6:6-7    = 6:-1
        int freq=it2->first+1;
        int diff=it1->first-it1->second;
        int cnt=freq-diff;
        if(cnt<=0) cnt=1;
        
        int end=it1->second-1;
        int start=cnt-1;
        if(end==start) res+=end;
        else res+=(end+start)*(end-start+1)/2;
        
        return cnt-1;        
    }
    
    void print(map<int,int>& frequency)
    {
        for(auto it=frequency.rbegin(); it!=frequency.rend(); ++it)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }
        cout<<endl;
    }
};

//2023-04-15
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    int minDeletions(string s)
    {                
        unordered_map<char, int> character;
        for(auto c: s)
        {
            ++character[c];
        }
        
        map<int, int> freqs;
        //int maxFreq=1;
        for(auto& it: character)
        {
            ++freqs[it.second];
            //maxFreq = max(maxFreq, freqs[it.second]);
        }
                
        set<int> validFreq;
        validFreq.insert(0);
        
        int ans=0;
        int pre=0;
        for(auto& it: freqs)
        {
            int freq=it.first;
            int cnt=it.second;
            
            for(int i=pre+1; i<freq; ++i)
            {
                validFreq.insert(i);
            }
            
            while(cnt > 1)
            {
                if(validFreq.size() == 1)
                {
                    ans += freq - 0;
                }
                else
                {
                    ans += freq - *(validFreq.rbegin());
                    validFreq.erase(std::prev(validFreq.end()));
                }
                
                --cnt;
            }
            
            pre=freq;
        }
        
        return ans;
    }
};
