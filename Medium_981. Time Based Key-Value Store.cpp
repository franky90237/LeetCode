//2022-09-13
//time  : O(log(n))
//space : O(n)
class TimeMap 
{
private:
    unordered_map<string, map<int,string>> data;
    
public:
    TimeMap()
    {
        
    }
    
    void set(string key, string value, int timestamp)
    {
        data[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp)
    {
        if(data.find(key)!=data.end())
        {
            auto it=data[key].lower_bound(timestamp);
            
            if(it==data[key].end())
            {
                --it;
                return it->second;
            }            
            
            if(it->first!=timestamp) 
            {
                if(it==data[key].begin()) return "";
                --it;
            }            
            
            return it->second;
        }
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
