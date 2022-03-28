//monotonic stack
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<pair<int,int>> s;
        
        s.push(pair<int,int>(-1,0));
        int n=heights.size();
        int max_size=0;
        int i;
        for(i=0; i<n; ++i)
        {
            while(heights[i]<s.top().second)
            {
                int height=s.top().second;
                s.pop();
                int width=i-s.top().first-1;
                //cout<<i<<"  - "<<height<<" , "<<width<<" = "<<height*width<<endl;
                max_size=max(max_size,height*width);
            }
            
            s.push(pair<int,int>(i,heights[i]));
        }
        
        while(s.size()>1)
        {
            int height=s.top().second;
            s.pop();
            int width=i-s.top().first-1;            
            max_size=max(max_size,height*width);
        }
        
        return max_size;
    }    
};
