//2022-08-02
class LRUCache
{
private:
    int max_size;
    list<int> cache;
    unordered_map<int,pair<int,list<int>::iterator>> record;    
    
public:
    LRUCache(int capacity) 
    {
        /*
        ["LRUCache","get","put","get","put","put","get","get"]
        [[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
        
        (2,6)
        (1,5) (2,6)
        (1,2) (2,6)
        
        */
        max_size=capacity;
    }
    
    int get(int key)
    {
        //cout<<"get : "<<key<<endl;
        if(record.find(key)!=record.end()) 
        {            
            int value=record[key].first;
            
            list<int>::iterator it=record[key].second;            
            cache.erase(it);            
                        
            cache.push_front(key);            
            record[key]={value,cache.begin()};
            
            //pirnt_list();
            return value;
        }
        
        return -1;
    }
    
    void put(int key, int value)
    {
        if(cache.size()==max_size && record.find(key)==record.end())
        {
            int leat_key=cache.back();
            
            cache.pop_back();
            record.erase(leat_key);        
        }
        
        if(record.find(key)!=record.end())
        {
            list<int>::iterator it=record[key].second;
            cache.erase(it);
            record.erase(key);
        }
        
        cache.push_front(key);        
        record[key]={value,cache.begin()};
        
        //pirnt_list();
    }
    
    void pirnt_list()
    {
        for(auto& it:cache)cout<<it<<", ";
        cout<<endl;        
    }
};

//2022-08-02
class LRUCache
{
private:
    int max_size;
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> record;    
    
public:
    LRUCache(int capacity) 
    {
        /*
        ["LRUCache","get","put","get","put","put","get","get"]
        [[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
        
        (2,6)
        (1,5) (2,6)
        (1,2) (2,6)
        
        */
        max_size=capacity;
    }
    
    int get(int key)
    {
        //cout<<"get : "<<key<<endl;
        if(record.find(key)!=record.end())
        {
            list<pair<int,int>>::iterator it=record[key];
            int value=(*it).second;
            cache.erase(it);
            
            cache.push_front({key,value});
            record[key]=cache.begin();
            
            //pirnt_list();
            return value;
        }
        
        return -1;
    }
    
    void put(int key, int value)
    {
        if(cache.size()==max_size && record.find(key)==record.end())
        {
            int least_key=cache.back().second;
            
            cache.pop_back();
            record.erase(least_key);        
        }
        
        if(record.find(key)!=record.end())
        {
            list<pair<int,int>>::iterator it=record[key];
            cache.erase(it);
            record.erase(key);
        }
        
        cache.push_front({key,value});
        record[key]=cache.begin();
        
        //pirnt_list();
    }
    
    void pirnt_list()
    {
        for(auto& it:cache) cout<<"("<<it.first<<","<<it.second<<") ";
        cout<<endl;        
    }
};
