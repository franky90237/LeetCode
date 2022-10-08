//2022-10-08
//time  : O(n)
//space : O(n)
class MyCalendarThree
{
private:
    map<int, int> s;
    map<int, int> e;
    int largestK;
    
public:
    MyCalendarThree() 
    {
        
    }
    
    int book(int start, int end) 
    {
        ++s[start];
        ++e[end];
                
        int k=0;
        auto pS=s.begin();
        auto pE=e.begin();        
        while(pS != s.end() && pE != e.end())
        {            
            if(pS->first < pE->first)
            {
                k += pS->second;
                ++pS;                                                
                largestK=max(largestK, k);
            }
            else
            {
                k -= pE->second;
                ++pE;                                
            }            
        }
        
        /*for(auto& i: s) cout<<"("<<i.first<<", "<<i.second<<") ";
        cout<<endl;
        for(auto& i: e) cout<<"("<<i.first<<", "<<i.second<<") ";
        cout<<endl;*/
        
        return largestK;
    }    
};

//2022-10-08
//time  : O(n)
//space : O(n)
class MyCalendarThree
{
private:
    map<int, int> calendar;    
    int largestK;
    
public:
    MyCalendarThree() 
    {
        
    }
    
    int book(int start, int end) 
    {
        ++calendar[start];
        --calendar[end];
                
        int k=0;
        auto it=calendar.begin();
        while(it != calendar.end())
        {
            k += it->second;
            largestK=max(largestK, k);
            ++it;
        }        
        
        return largestK;
    }
};
