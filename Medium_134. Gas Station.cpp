//2022-09-08
//TLE
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        /*
        n=1
        [4] [1]
        cnt : 0 -> 1
        cur : 0 -> 0
        tank: 0+4-1 -> 3

        n=2
        [4,0] [1,2]
        cnt : 0 -> 1 -> 2
        cur : 0 -> 1 -> 0
        tank: 0 -> 3 -> 2

        n=2
        [4,2] [4,5]
        cnt : 0 -> 1 -> 
        cur : 0 -> 1 -> 
        tank: 0 -> 0 -> -3(X)
        */
        
        int n=gas.size();    
        for(int i=0; i<n; ++i)
        {
            if(gas[i]>=cost[i] && check(i,gas,cost)) return i;
        }
        
        return -1;
    }
    
    bool check(int cur, vector<int>& gas, vector<int>& cost)
    {
        int n=gas.size();
        
        int cnt=0;
        int tank=0;
        
        while(cnt<n)
        {
            tank=tank+gas[cur]-cost[cur];
            if(tank<0) return false;            
            
            cur=(cur+1)%n;
            ++cnt;
        }
        
        return true;
    }
};

//2022-09-08
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        /*
        [0, 1, 2, 3, 4]
        [0, 0, 0,-5,10]
        (0,0) (0,1) (0,2) (-5,3) (10,4)
        (-5,3) (0,0) (0,1) (0,2) (10,4)
        */
        int n=gas.size();       
        
        vector<vector<int>> diff_idx;
        
        long sum=0;
        for(int i=0; i<n; ++i)
        {
            gas[i]=gas[i]-cost[i];
            diff_idx.push_back({gas[i],i});
            sum=sum+gas[i];
        }        
        if(sum<0) return -1;
                
        sort(diff_idx.begin(),diff_idx.end());
        for(int i=n-1; i>=0; --i)
        {
            if(diff_idx[i][0]<0) break;
            
            int start=diff_idx[i][1];
            if(check(start,gas)) return start;
        }
        
        return -1;
    }
    
    bool check(int cur, vector<int>& gas)
    {
        int n=gas.size();
               
        int sum=0;  
        for(int cnt=0; cnt<n; ++cnt)
        {
            sum+=gas[cur];
            if(sum<0) return false;            
            
            cur=(cur+1)%n;        
        }
        
        return true;
    }
};

//2022-09-08
//time  : O(n)
//space : O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        /*
         0, 1, 2, 3, 4
        [0, 0, 0,-5,10]
        
        */
        int n=gas.size();       
        
        int all=0;
        int cur=0;
        int start=0;        
        for(int i=0; i<n; ++i)
        {
            int rest=gas[i]-cost[i];
            cur+=rest;
            all+=rest;
            
            if(cur<0)
            {
                cur=0;
                start=i+1;
            }
        }                
        
        if(all<0) return -1;
        return start;
    }
        
};
