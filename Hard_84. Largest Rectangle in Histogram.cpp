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

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n=heights.size();
        
        int left_boundary[n];
        left_boundary[0]=-1;
        for(int i=1; i<n; ++i)
        {
            int pre=i-1;
            while(pre>=0 && heights[i]<=heights[pre]) pre=left_boundary[pre];
            
            left_boundary[i]=pre;
        }
                
        int right_boundary[n];
        right_boundary[n-1]=n;
        for(int i=n-2; i>=0; --i)
        {
            int pre=i+1;
            while(pre<n && heights[i]<=heights[pre]) pre=right_boundary[pre];
            
            right_boundary[i]=pre;
        }
        
        int max_size=0;
        for(int i=0; i<n; ++i)
        {
            int height=heights[i];            
            int width=right_boundary[i]-left_boundary[i]-1;
            max_size=max(max_size,height*width);
        }
        
        return max_size;
    }    
};

//2023-08-25
//time  : O(n)
//space : O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n=heights.size();
        vector<int> left(n);
        vector<int> right(n);
        
        left[0]=0;
        for(int i=1; i<n; ++i)
        {
            if(heights[i] > heights[i-1]) left[i]=i;
            else 
            {
                int cur=i-1;
                do
                {
                    left[i]=left[cur];
                    cur=left[i]-1;
                } while(cur >= 0 && heights[cur] >= heights[i]);
            }
        }
        
        right[n-1]=n-1;
        for(int i=n-2; i>=0; --i)
        {
            if(heights[i] > heights[i+1]) right[i]=i;
            else 
            {
                int cur=i+1;
                do
                {
                    right[i]=right[cur];
                    cur=right[i]+1;
                } while(cur < n && heights[cur] >= heights[i]);
            }
        }
        
        int ans=0;
        for(int i=0; i<n; ++i)
        {
            int area=heights[i]*(right[i]-left[i]+1);
            ans=max(ans, area);
        }
        
        return ans;
    }
};

//2023-08-25
//time  : O(n)
//space : O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n=heights.size();
        stack<int> monoStack;
        monoStack.push(-1);
        int ans=0;
        for(int i=0; i<n; ++i)
        {
            while(monoStack.top() != -1 && heights[monoStack.top()] > heights[i])
            {
                int height=heights[monoStack.top()];                
                monoStack.pop();
                int length=i-monoStack.top()-1;
                ans=max(ans, height*length);
            }
            
            monoStack.push(i);
        }
        
        while(monoStack.top() != -1)
        {
            int height=heights[monoStack.top()];                
            monoStack.pop();
            int length=n-monoStack.top()-1;
            ans=max(ans, height*length);
        }
        
        return ans;
    }
};
