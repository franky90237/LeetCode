//array
class MyHashSet 
{
private:
    vector<vector<int>> buckets;    
    
public:
    MyHashSet() 
    {        
        buckets.resize(1000);        
    }
    
    void add(int key) 
    {
        int bucket=key % buckets.size();
        
        if(!contains(key)) buckets[bucket].push_back(key);                
    }
    
    void remove(int key) 
    {        
        int bucket=key % buckets.size();
        int size=buckets[bucket].size();
        
        for(int i=0;i<size;++i)
        {
            if(buckets[bucket][i]==key) 
            {
                for(int j=i+1;j<size;++j)
                {
                    buckets[bucket][j-1]=buckets[bucket][j];
                }
                
                buckets[bucket].resize(size-1);
            }
        }                
    }
    
    bool contains(int key) 
    {
        int bucket=key % buckets.size();
        
        bool duplicate=false;
        for(int i=0;i<buckets[bucket].size();++i)
        {
            if(buckets[bucket][i]==key) 
            {
                duplicate=true;
                break;
            }
        }
        
        return duplicate;
    }
};

//link list
class MyHashSet 
{
private:
    vector<list<int>> buckets;    
    
    int hash(int key)
    {
        return key % buckets.size();
    }
    
public:
    MyHashSet() : buckets(1000)
    {
        
    }       
    
    void add(int key) 
    {
        if(!contains(key)) 
        {
            int bucket=hash(key);
            buckets[bucket].push_back(key);
        }
    }
    
    void remove(int key) 
    {
        int bucket=hash(key);
        
        for(auto it=buckets[bucket].begin(); it!=buckets[bucket].end(); ++it)
        {
            if(*it==key) 
            {
                buckets[bucket].erase(it);
                return;
            }
        }
    }
    
    bool contains(int key)
    {
        int bucket=hash(key);
                        
        for(int i:buckets[bucket])
        {
            if(i==key) return true;
        }
        
        return false;
    }
};

//link list with loading_factor
class MyHashSet 
{
private:
    vector<list<int>> buckets;    
    int capacity;
    int count;
    int loading_factor;
    
    int hash(int key)
    {
        return key % buckets.size();
    }
    
    void rehash()
    {
        capacity*=2;
        buckets.resize(capacity);        
    }
    
public:
    MyHashSet() : capacity(1000), count(0), loading_factor(0.75), buckets(1000) 
    {
        
    }       
    
    void add(int key) 
    {
        if(contains(key)) return; 
        
        if(loading_factor*capacity>=count) rehash();
        
        int bucket=hash(key);
        buckets[bucket].push_back(key);
        ++count;
    }
    
    void remove(int key) 
    {
        int bucket=hash(key);
        
        for(auto it=buckets[bucket].begin(); it!=buckets[bucket].end(); ++it)
        {
            if(*it==key) 
            {
                buckets[bucket].erase(it);
                --count;
                return;
            }
        }
    }
    
    bool contains(int key)
    {
        int bucket=hash(key);
                        
        for(int i:buckets[bucket])
        {
            if(i==key) return true;
        }
        
        return false;
    }
};
