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

//2022-10-06
//time  : O(log(n))
class TimeMap 
{
private:
    unordered_map<string, map<int, string>> table;
    
public:
    TimeMap() 
    {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        table[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) 
    {
        if(table.find(key) == table.end()) return "";
        
        auto it=table[key].lower_bound(timestamp);
        if(it == table[key].end())
        {
            --it;
            return it->second;
        }
        else
        {
            if(it->first == timestamp) return it->second;            
            if(it == table[key].begin()) return "";
            
            --it;
            return it->second;
        }
    }
};
