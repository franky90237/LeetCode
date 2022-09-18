//2022-05-27
//time  : O(32)
//space : O(1)
class Solution {
public:
    int numberOfSteps(int num) 
    {
        if(num<=2) return num;
        
        int res=0;
        while(num!=1)
        {
            if(num&1==1) res+=1;
            res+=1;
            num=num>>1;
        }
        
        return res+1;
    }
};

//2022-09-18
//monotonic stack
//time  : O(n)
//space : O(n)
class Solution {
public:
    int trap(vector<int>& height)
    {
        int n=height.size();
        
        stack<int> mono_s;
        int ans=0;
        for(int i=0; i<n; ++i)
        {
            while(!mono_s.empty() && height[i] > height[mono_s.top()])
            {
                int mid=mono_s.top();
                mono_s.pop();
                
                if(mono_s.empty()) break;
                
                int right_bar=height[i];
                int left_bar=height[mono_s.top()];
                int w=i-mono_s.top()-1;
                int h=min(left_bar, right_bar)-height[mid];
                
                ans += w*h;
            }
            
            mono_s.push(i);
        }              
        
        return ans;
    }
};

//2022-09-18
//time  : O(n)
//space : O(1)
class Solution {
public:
    int trap(vector<int>& height)
    {
        int n=height.size();
        
        int left_max=0;
        int right_max=0;
        
        int ans=0;
        int l=0;
        int r=n-1;      
        while(l<r)
        {
            left_max=max(left_max, height[l]);
            right_max=max(right_max, height[r]);
            
            if(left_max<right_max)
            {
                if(height[l]<left_max)
                {
                    ans+=left_max-height[l];
                }
                
                ++l;
            }
            else
            {
                if(height[r]<right_max)
                {
                    ans+=right_max-height[r];
                }
                
                --r;
            }
        }
        
        return ans;
    }
};
