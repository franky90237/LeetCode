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

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
