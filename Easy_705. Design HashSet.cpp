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
    
public:
    MyHashSet() : buckets(1000)
    {        
        //buckets.resize(1000);        
    }
    
    int hash(int key)
    {
        return key % buckets.size();
    }
    
    list<int>::iterator search(int key)
    {
        int bucket=hash(key);
        
        auto it=buckets[bucket].begin();
        for(; it!=buckets[bucket].end(); ++it)
        {
            if(*it==key) break;
        }
        
        return it;
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
        list<int>::iterator it=search(key);
        int bucket=hash(key);
        if(it==buckets[bucket].end()) return;
        
        buckets[bucket].erase(it);
        
        
        /*int bucket=key % buckets.size();
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
        }*/
    }
    
    bool contains(int key) 
    {
        return search(key)!=buckets[hash(key)].end();
        
        /*
        int bucket=hash(key);
        
        bool duplicate=false;
        for(int i=0;i<buckets[bucket].size();++i)
        {
            if(buckets[bucket][i]==key) 
            {
                duplicate=true;
                break;
            }
        }
        
        return duplicate;*/
    }
};
