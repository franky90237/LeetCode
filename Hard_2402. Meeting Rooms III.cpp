//2022-09-06
//time  : O(nlogn + mlogm)
//space : O(n)
class Solution 
{
private:
    typedef pair<long, long> pll;
    
public:
    int mostBooked(int n, vector<vector<int>>& meetings)
    {
        sort(meetings.begin(),meetings.end());
        
        int cnt[n];
        set<int> rooms;
        for(int i=0; i<n; ++i) 
        {
            cnt[i]=0;
            rooms.insert(i);
        }
        
        priority_queue<pll, vector<pll>, greater<pll> > used_room_meetings;
        
        int len=meetings.size();        
        for(int i=0; i<len; ++i)
        {
            //cout<<i<<endl;
            
            long end=meetings[i][0];
            while((!used_room_meetings.empty() && meetings[i][0]>=used_room_meetings.top().first) || rooms.empty())
            {
                end=max(end,used_room_meetings.top().first);
                
                int room=used_room_meetings.top().second;                            
                rooms.insert(room);
                used_room_meetings.pop();
            }
            
            int room=*(rooms.begin());
            rooms.erase(rooms.begin());
            ++cnt[room];
            
            int period=meetings[i][1]-meetings[i][0];
            used_room_meetings.push({end+period,room});
        }               
               
        int max_cnt=cnt[0];
        int room=0;
        for(int i=0; i<n; ++i)
        {
            //cout<<i<<" "<<cnt[i]<<endl;
            if(cnt[i]>max_cnt)
            {
                max_cnt=cnt[i];
                room=i;
            }
        }
        
        return room;        
    }
};
