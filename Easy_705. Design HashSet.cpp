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
