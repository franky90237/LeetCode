//2022-08-04
//time  : O(n)
class MyCalendar 
{
private:
    set<pair<int,int>> events;
    
    bool overlap(int start, int end)
    {
        int& new_start=start;
        int& new_end=end;
        
        for(auto& event:events)
        {
            int cur_start=event.first;
            int cur_end=event.second;
            
            if(new_start >= cur_end) continue;
            if(new_end <= cur_start) break;
            
            if((new_start >= cur_start && new_start < cur_end) ||
               (new_start < cur_start  && new_end >= cur_start))                
            {
                return true;
            }
        }
        
        return false;
    }
    
public:
    MyCalendar() 
    {
        /*
        ------     --------     ----------- ----------
           ----
                ------
                --------------
                
        1. new_start >= cur_start && new_start <= cur_end
        2. new_start < cur_start  && new_end >= cur_start
        
        (10,20)
        (15,25)
        (20,30)
        (9,15)
        (20,20)
        (9,25)
        
        cur_s=10, cur_e=20
        new_s=9, new_s=15
        */
    }
    
    bool book(int start, int end) 
    {
        if(!overlap(start,end)) 
        {
            events.insert({start,end});
            return true;
        }
        
        return false;
    }
};
