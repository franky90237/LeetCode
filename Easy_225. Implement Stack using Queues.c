//two queue
class MyStack {
private:
    queue<int> main;
    queue<int> aug;
    int size=0;
    int queue_number;
    
public:
    MyStack() 
    {
        size=0;
        queue_number=0;
    }
    
    void push(int x) 
    {
        if(queue_number==0)
        {
            main.push(x);
        }
        else
        {
            aug.push(x);
        }
        
        ++size;
    }
    
    int pop() 
    {
        --size;
        
        if(queue_number==0)
        {
            queue_number=(queue_number+1)%2;
            
            while(main.size()>1)
            {
                aug.push(main.front());
                main.pop();                
            }
            
            int pop_val=main.front();
            main.pop();
            return pop_val;
        }
        else
        {
            queue_number=(queue_number+1)%2;
            
            while(aug.size()>1)
            {
                main.push(aug.front());
                aug.pop();
            }
            
            int pop_val=aug.front();           
            aug.pop();
            return pop_val;
        }        
    }
    
    int top() 
    {
        int pop_val;
        
        if(queue_number==0)
        {
            while(!main.empty())
            {
                pop_val=main.front();
                aug.push(pop_val);
                main.pop();                
            }
        }
        else
        {
            while(!aug.empty())
            {
                pop_val=aug.front();
                main.push(pop_val);
                aug.pop();                
            }
        }
        
        queue_number=(queue_number+1)%2;
        
        return pop_val;
    }
    
    bool empty() 
    {
        return size==0;
    }
};

//one queue
//push  O(1)
//pop   O(n)
//top   O(n)
class MyStack {
private:
    queue<int> q;    
    int size=0;    
    
public:
    MyStack() 
    {
        size=0;        
    }
    
    void push(int x) 
    {
        q.push(x);
        ++size;
    }
    
    int pop() 
    {        
        int cnt=size;
        
        while(cnt>1)
        {
            q.push(q.front());
            q.pop();            
            
            --cnt;
        }
        
        int top=q.front();
        q.pop();
        --size;
        
        return top;      
    }
    
    int top() 
    {
        int top;
        int cnt=size;
        
        while(cnt>0)
        {
            top=q.front();
            q.pop();
            q.push(top);
            
            --cnt;
        }        
        
        return top;
    }
    
    bool empty() 
    {
        return size==0;
    }
};

//one queue
//push  O(n)
//pop   O(1)
//top   O(1)
class MyStack {
private:
    queue<int> q;
    
public:
    MyStack() 
    {
    }
    
    void push(int x) 
    {
        int size=q.size();
        
        q.push(x);
        for(int i=0;i<size;++i)
        {
            q.push(pop());
        }                
    }
    
    int pop() 
    {        
        int top=q.front();
        q.pop();
        return top;      
    }
    
    int top() 
    {        
        return q.front();
    }
    
    bool empty() 
    {
        return q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
