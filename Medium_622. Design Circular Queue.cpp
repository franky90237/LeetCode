class MyCircularQueue {
private:
    int *q;
    int size;
    int front;
    int rear;
    
public:
    MyCircularQueue(int k) 
    {
        q=new int[k];
        size=k;
        front=-1;
        rear=-1;
    }
    
    bool enQueue(int value) 
    {
        if(isFull()) return false;
        
        if(!isEmpty())
        {
            rear=(rear+1)%size;            
        }
        else
        {
            ++front;
            ++rear;            
        }
        
        q[rear]=value;
        
        return true;
    }
    
    bool deQueue() 
    {
        if(isEmpty()) return false;
        
        if(rear==front)
        {
            rear=-1;
            front=-1;
        }
        else
        {
            front=(front+1)%size;
        }
        
        return true;
    }
    
    int Front() 
    {
        if(front==-1) return -1;
        return q[front];
    }
    
    int Rear() 
    {
        if(rear==-1) return -1;
        return q[rear];        
    }
    
    bool isEmpty()
    {
        if(front==-1 && rear==-1) return true;
        return false;
    }
    
    bool isFull() 
    {
        if((rear+1)%size==front) return true;
        return false;
    }
};

//2022-07-28
class MyCircularQueue
{
private:
    vector<int> queue;
    int cnt;
    int front;
    int rear;
    
public:
    MyCircularQueue(int k) 
    {
        queue.resize(k);
        cnt=0;
        front=0;
        rear=0;
    }
    
    bool enQueue(int value) 
    {
        if(isFull()) return false;
                
        queue[rear]=value;
        rear=(rear+1)%queue.size();
        ++cnt;
        return true;
    }
    
    bool deQueue()
    {
        if(isEmpty()) return false;
        
        front=(front+1)%queue.size();
        --cnt;
        return true;
    }
    
    int Front()
    {
        if(isEmpty()) return -1;
        return queue[front];
    }
    
    int Rear()
    {
        if(isEmpty()) return -1;
        int pre=(rear-1 < 0) ? queue.size()-1 : rear-1;
        return queue[pre];
    }
    
    bool isEmpty()
    {
        return cnt==0;
    }
    
    bool isFull()
    {
        return cnt==queue.size();
    }
};
