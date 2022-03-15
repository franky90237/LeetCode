class RandomizedSet 
{
private:
    unordered_map<int,int> m;
    vector<int> key;
    
public:
    RandomizedSet()
    {
        
    }
    
    bool insert(int val) 
    {
        if(m.find(val)!=m.end()) return false;
        
        m[val]=key.size();
        key.push_back(val);
        return true;
    }
    
    bool remove(int val) 
    {
        if(m.find(val)==m.end()) return false;
        
        int last_key=key.back();
        int remove_index=m[val];
        key[remove_index]=last_key;
        key.pop_back();
        m[last_key]=remove_index;
        
        m.erase(val);
        
        return true;
    }
    
    int getRandom()
    {
        /*random_device rd;
        mt19937 generator( rd() );
        uniform_int_distribution<int> unif(0,m.size());
        int target=unif(generator);*/
        
        //srand(time(0));
        return key[rand()%key.size()];
    }
};
