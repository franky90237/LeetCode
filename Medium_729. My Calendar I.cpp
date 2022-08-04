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

//2022-08-04
//clear condition
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
                        
            if((new_start < cur_end) && (new_end > cur_start)) return true;
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
                
        not overlap : (new_start >= cur_end) || (new_end <= cur_start)
        overlpa : (new_start < cur_end) && (new_end > cur_start)
        
        (47,50)
        (33,41)
        (25,32)
        (19,25)
        
        cur_s=10, cur_e=20
        new_s=5, new_s=8
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

//2022-08-04
//clear condition + lowe bound
//time  : O(n)
class MyCalendar 
{
private:
    set<pair<int,int>> events;
    
    bool overlap(int start, int end)
    {
        if(events.empty()) return false;
        
        int& new_start=start;
        int& new_end=end;
        
        set<pair<int,int>>::iterator it=events.upper_bound({start,end});
        //cout<<start<<"  "<<end<<" ---- ";
        //cout<<it->first<<" "<<it->second<<endl;
        
        while(true)
        {            
            int cur_start=it->first;
            int cur_end=it->second;
                        
            if((new_start < cur_end) && (new_end > cur_start)) return true;
            
            if(it==events.begin()) break;
            --it;            
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
                
        not overlap : (new_start >= cur_end) || (new_end <= cur_start)
        overlpa : (new_start < cur_end) && (new_end > cur_start)
        
        (47,50)
        (33,41)
        (25,32)
        (19,25)
        
        cur_s=10, cur_e=20
        new_s=5, new_s=8
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
