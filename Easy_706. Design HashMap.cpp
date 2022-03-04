class MyHashMap 
{
private:
    int capacity;
    int count;
    double loading_factor;
    vector<list<pair<int,int>>> buckets;
    
    int hash(int key)
    {
        return key % buckets.size();
    }
    
    void rehash()
    {
        capacity*=1.01;
        buckets.resize(capacity);
        //cout<<buckets.size()<<endl;
    }
    
public:
    MyHashMap() : capacity(1000), count(0), loading_factor(0.85), buckets(capacity) 
    {
        //cout<<buckets.max_size();
    } 
    
    void put(int key, int value) 
    {        
        //if(loading_factor*capacity>=count) rehash();
        
        int bucket=hash(key);
        
        for(auto it=buckets[bucket].begin(); it!=buckets[bucket].end(); ++it)
        {
            if(it->first==key) 
            {               
                it->second=value;                
                return;
            }
        }
        
        buckets[bucket].push_back(pair<int,int>(key,value));
        ++count;        
    }
    
    int get(int key) 
    {
        int bucket=hash(key);
                        
        for(auto& i:buckets[bucket])
        {
            if(i.first==key) return i.second;
        }
        
        return -1;        
    }
    
    void remove(int key) 
    {
        int bucket=hash(key);
        
        for(auto it=buckets[bucket].begin(); it!=buckets[bucket].end(); ++it)
        {
            if(it->first==key) 
            {
                buckets[bucket].erase(it);
                --count;
                return;
            }
        }        
    }
};
