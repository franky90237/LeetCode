//2022-07-12
//use max_heap and the line sweep concepts
//time  : O(nlog(n))
//space : O(n)
class Solution 
{
private:
    enum TYPE {start,end};
    
    class Entry
    {
    public:
        int x;
        int y;
        int type;
                
        Entry(int x, int y, int type):x(x), y(y), type(type) {}
    };
    
    struct line_comp
    {
    public:
        bool operator()(const Entry& a, const Entry& b)
        {
            if(a.x==b.x)
            {
                if(a.type==0 && b.type==0) return a.y>b.y;
                else if(a.type==1 && b.type==1) return a.y<b.y;
                else return (a.type==0 && b.type==1);               
            }
            
            return a.x<b.x;
        }
    } line_comp;
    
    class max_heap_comp
    {
    public:
        bool operator()(const pair<int,int>& a, const pair<int,int>& b)
        {            
            return a.first<b.first;
        }
    };
    
    
    void max_heap_remove_by_y(int y, priority_queue<pair<int,int>,vector<pair<int,int>>,max_heap_comp>& max_heap, unordered_map<int,int>& support)
    {
        if(max_heap.top().first==y)
        {
            //cout<<y<<" : "<<support.size()<<endl;
            max_heap.pop();
            while(support.find(max_heap.top().first)!=support.end())
            {
                //cout<<max_heap.top().first<<" ,, "<<max_heap.size()<<endl;
                if(support[max_heap.top().first]==1) support.erase(max_heap.top().first);
                else --support[max_heap.top().first];
                max_heap.pop();
            }
        }
        else
        {
            ++support[y];
        }
    }
    
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        vector<Entry> line;
        for(auto building:buildings)
        {
            line.push_back(Entry(building[0],building[2],0));
            line.push_back(Entry(building[1],building[2],1));
        }
        
        //line_comp comp;
        sort(line.begin(),line.end(),line_comp);
                
        priority_queue<pair<int,int>,vector<pair<int,int>>,max_heap_comp> max_heap;
        max_heap.push(pair<int,int>(0,0));
        unordered_map<int,int> support;
        
        vector<vector<int>> ans;
        for(auto& i:line)
        {
            //cout<<i.x<<" "<<i.y<<" "<<i.type<<endl;
            
            if(i.type==0)
            {
                if(max_heap.empty() || i.y>max_heap.top().first) ans.push_back({i.x,i.y});
                max_heap.push(pair<int,int>(i.y,i.type));
                //++max_heap_item[i.y];
            }
            else
            {
                max_heap_remove_by_y(i.y,max_heap,support);
                if(i.y>max_heap.top().first) ans.push_back({i.x,max_heap.top().first});
            }
        }
        
        return ans;
    }
};

//2022-10-01
class Solution {
private:
    static bool comp_sort(const vector<int>& a, const vector<int>& b)
    {
        if(a[0] == b[0])
        {
            if(a[2] == -1 && b[2] == -1) return a[1] < b[1];
            else if(a[2] == 1 && b[2] == 1) return a[1] > b[1];
            else return a[2] > b[2];
        }
        
        return a[0] < b[0];
    } 
    
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {        
        vector<vector<int>> input;
        for(auto& building : buildings)
        {
            input.push_back({building[0], building[2], 1});
            input.push_back({building[1], building[2], -1});
        }
        
        sort(input.begin(), input.end(), comp_sort);
        
        vector<vector<int>> ans;
        priority_queue<int> maxHeap;        
        unordered_map<int, int> to_be_removed;
        
        int preHeight=0;
        int i=0;
        int n=input.size();
        while(i < n)
        {
            if(input[i][2] == 1)
            {
                maxHeap.push(input[i][1]);                               
            }
            else
            {            
                removed_mapHeap_elemet(maxHeap, to_be_removed, input[i][1]);
            }
                        
            int curHeight=maxHeap.empty() ? 0 : maxHeap.top();
            //cout<<maxHeap.size()<<" | "<<input[i][0]<<" "<<input[i][1]<<" : "<<preHeight<<" "<<curHeight<<endl;
            if(curHeight != preHeight)
            {
                ans.push_back({input[i][0], curHeight});
                preHeight=curHeight;
            }
            
            ++i;
        }
        
        return ans;        
    }
    
    void removed_mapHeap_elemet(priority_queue<int>& maxHeap, unordered_map<int, int>& to_be_removed, int val)
    {
        if(maxHeap.top() == val)
        {                       
            maxHeap.pop();
            while(!maxHeap.empty() && to_be_removed.find(maxHeap.top()) != to_be_removed.end())
            {                                
                --to_be_removed[maxHeap.top()];
                if(to_be_removed[maxHeap.top()] == 0) to_be_removed.erase(maxHeap.top());
                maxHeap.pop();
            }                        
        }
        else
        {
            ++to_be_removed[val];
        }
    }
};

//2022-10-01
//using binary search tree (set) to replace maxHeap
class Solution {
private:
    static bool comp_sort(const vector<int>& a, const vector<int>& b)
    {
        if(a[0] == b[0])
        {
            if(a[2] == -1 && b[2] == -1) return a[1] < b[1];
            else if(a[2] == 1 && b[2] == 1) return a[1] > b[1];
            else return a[2] > b[2];
        }
        
        return a[0] < b[0];
    } 
    
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {        
        vector<vector<int>> input;
        for(auto& building : buildings)
        {
            input.push_back({building[0], building[2], 1});
            input.push_back({building[1], building[2], -1});
        }
        
        sort(input.begin(), input.end(), comp_sort);
        
        vector<vector<int>> ans;        
        multiset<int> maxHeap;
        
        int preHeight=0;
        int i=0;
        int n=input.size();
        while(i < n)
        {
            if(input[i][2] == 1)
            {
                maxHeap.insert(input[i][1]);                               
            }
            else
            {            
                maxHeap.erase(maxHeap.find(input[i][1]));
            }
                        
            int curHeight=maxHeap.empty() ? 0 : *(maxHeap.rbegin());
            //cout<<maxHeap.size()<<" | "<<input[i][0]<<" "<<input[i][1]<<" : "<<preHeight<<" "<<curHeight<<endl;
            if(curHeight != preHeight)
            {
                ans.push_back({input[i][0], curHeight});
                preHeight=curHeight;
            }
            
            ++i;
        }
        
        return ans;        
    }
};
