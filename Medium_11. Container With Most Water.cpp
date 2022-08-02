//2022-05-25
//TLE
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int n=height.size();
        
        int res=0;
        for(int left=0; left<n; ++left)
        {
            for(int right=left+1; right<n; ++right)
            {
                int water=min(height[left],height[right])*(right-left);
                res=max(res,water);
            }
        }
        
        return res;
    }
};

//2022-05-25
//greedy
//time  : O(n)
//space : O(1)
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int n=height.size();
        
        int left=0;
        int right=n-1;
        int res=0;
        
        while(left<right)
        {
            int width=right-left;
            
            if(height[left]<height[right])
            {
                res=max(res,height[left]*width);
                ++left;
            }
            else
            {
                res=max(res,height[right]*width);
                --right;
            }
        }
        
        return res;
    }
};

//2022-08-02
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int n=height.size();
        
        int max_area=0;
        for(int i=0; i<n; ++i)
        {            
            cal_max_area(height,0,i,max_area,true);
            cal_max_area(height,i,n-1,max_area,false);
            //cout<<i<<" "<<max_area<<endl;
        }
        
        return max_area;
    }
    
    void cal_max_area(vector<int>& height, int left, int right, int& max_area, bool left_to_right)
    {
        if(left_to_right)
        {
            for(int i=left; i<right; ++i)
            {
                int area=height[right]*(right-i);                
                if(area <= max_area) return;
                
                if(height[i]>=height[right] && area > max_area) 
                {
                    max_area=area;
                    return;
                }
            }
        }
        else
        {
            for(int i=right; i>left; --i)
            {
                int area=height[left]*(i-left);
                if(area <= max_area) return;
                
                if(height[i]>=height[left] && area > max_area) 
                {
                    max_area=area;
                    return;
                }
            }
        }
    }
};
