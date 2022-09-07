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

//2022-08-02
//greedy
//time  : O(n)
//space : O(1)
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int n=height.size();
        
        int max_area=0;
        int left=0;
        int right=n-1;
        while(left<right)
        {
            int width=right-left;
            
            if(height[left]<height[right])
            {                
                max_area=max(max_area,height[left]*width);
                ++left;
            }
            else
            {
                max_area=max(max_area,height[right]*width);
                --right;
            }            
        }
        
        return max_area;
    }     
};

//2022-09-07
//proof inspireed from : https://leetcode.com/problems/container-with-most-water/discuss/1069746/JS-Python-Java-C%2B%2B-or-2-Pointer-Solution-w-Visual-Explanation-or-beats-100
//time  : O(n)
//space : O(1)
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int ans=0;
        
        int left=0;
        int right=height.size()-1;
        
        while(left<right)
        {
            int water=(right-left)*min(height[left],height[right]);
            ans=max(ans,water);
            
            if(height[left]<height[right])
            {
                ++left;
                while(left<right && height[left]<=height[left-1]) ++left;
            }
            else
            {
                --right;
                while(left<right && height[right]<=height[right+1]) --right;
            }
        }
        
        return ans;
    }
};
