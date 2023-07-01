//2022-06-09
//time  : O(n)
//space : O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int n=numbers.size();
        
        unordered_map<int,vector<int>> dict;
        unordered_map<int,int> visited;
        for(int i=0; i<n; ++i) 
        {
            dict[numbers[i]].push_back(i);
            visited[i]=false;
        }
                
        for(int i=0; i<n; ++i)
        {
            if((i!=0 && numbers[i-1]==numbers[i]) || visited[i]) continue;
            
            int diff=target-numbers[i];
            if(dict.find(diff)==dict.end()) continue;
            if(diff==numbers[i]) return {dict[numbers[i]][0]+1,dict[numbers[i]][1]+1};
            return {dict[numbers[i]][0]+1,dict[diff][0]+1};
        }
        
        return {};
    }
};

//2022-06-09
//two pointer
//time  : O(n)
//space : O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int left=0;
        int right=numbers.size()-1;
        
        while(left<right)
        {
            int sum=numbers[left]+numbers[right];
            if(sum==target) return {left+1,right+1};
            else if(sum>target) --right;
            else ++left;
        }
        
        return {};
    }
};

//2022-07-19
//two pointer
//time  : O(n)
//space : O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int left=0;
        int right=numbers.size()-1;
        
        while(left<right)
        {
            int sum=numbers[left]+numbers[right];
            
            if(sum==target) return {left+1,right+1};
            else if(sum<target) ++left;
            else --right;
        }
        
        return {-1,-1};
    }
};

//2023-07-01
//time  : O(n)
//space : O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {        
        int n=numbers.size();
        int left=0;
        int right=n-1;
        while(left < right)
        {
            int sum=numbers[left]+numbers[right];
            if(sum == target)
            {
                break;
            }
            else if(sum > target)
            {
                --right;
            }
            else
            {
                ++left;
            }
        }
        
        return {left+1, right+1};
    }
};
