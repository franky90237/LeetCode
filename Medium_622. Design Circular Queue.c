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

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
