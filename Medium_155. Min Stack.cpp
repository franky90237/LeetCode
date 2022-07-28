class MinStack 
{
private:
    vector<int> s;
    int size;    

public:
    MinStack() 
    {
        size=0;        
    }
    
    void push(int val) 
    {
        s.push_back(val);
        ++size;        
    }
    
    void pop() 
    {
        if(size<=0) return;
        
        s.pop_back();
        --size;
    }
    
    int top() 
    {
        return s.back();
    }
    
    int getMin()
    {
        int minimum=INT_MAX;
        for(int i=0;i<size;++i) if(s[i]<minimum) minimum=s[i];        
        return minimum;
    }
};

//
class MinStack 
{
private:
    vector<int> s;
    vector<int> min_s;    

public:
    MinStack() 
    {
        
    }
    
    void push(int val) 
    {
        s.push_back(val);
        if(min_s.empty() || val<=getMin()) min_s.push_back(val);       
    }
    
    void pop() 
    {                
        if(top()==getMin()) min_s.pop_back();
        s.pop_back();        
    }
    
    int top() 
    {
        return s.back();
    }
    
    int getMin()
    {            
        //for(int i=0;i<min_s.size();++i) cout<<min_s[i]<<" ";
        //cout<<endl;
        return min_s.back();
    }
};

//2022-07-28
//two stack
class MinStack 
{
private:
    vector<int> s;
    vector<int> min_s;
    
public:
    MinStack() 
    {
        /*         
        5 4 3 7 9 6 2
                    ^ 
        s1 : 5 4 3 7 9 6 2
        s2 : 5 4 3 2
        
        */
    }
    
    void push(int val)
    {
        s.push_back(val);
        if(min_s.empty() || val<=min_s.back()) min_s.push_back(val);
    }
    
    void pop()
    {
        if(s.back()==min_s.back()) min_s.pop_back();
        s.pop_back();
    }
    
    int top()
    {
        return s.back();
    }
    
    int getMin()
    {
        return min_s.back();
    }
};
