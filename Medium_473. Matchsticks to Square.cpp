//2022-07-13
//dfs + backtracking
//time  : O(4^n)
//space : O(n)
class Solution {
public:    
    bool makesquare(vector<int>& matchsticks)
    {    
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4!=0) return false;
        
        int length=sum/4;
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        
        vector<int> side_length(4,0);
        return solve(0,matchsticks,side_length,length);         
        
        return true;
    }
    
    bool solve(int cur, vector<int>& matchsticks, vector<int>& side_length, int length)
    {
        int n=matchsticks.size();
        if(cur==n) return (side_length[0]==side_length[1] && side_length[1]==side_length[2] && side_length[2]==side_length[3]);
        
        for(int i=0; i<4; ++i)
        {
            if(side_length[i]+matchsticks[cur]>length) continue;
            
            side_length[i]+=matchsticks[cur];
            
            if(solve(cur+1,matchsticks,side_length,length)) 
            { 
                //print(side_length); 
                return true; 
            }            
            //else print(side_length);
            
            side_length[i]-=matchsticks[cur];
        }
        
        return false;
    }
    
    void print(vector<int>& side_length)
    {
        for(int i=0; i<4; ++i)
        {
            cout<<side_length[i]<<" ";        
        }
        cout<<endl;
    }
};

//2022-07-13
//dfs + backtracking + dp(duplicate side_legth skip)
//time  : O(4^n)
//space : O(n)
class Solution {
public:    
    bool makesquare(vector<int>& matchsticks)
    {    
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4!=0) return false;
        
        int length=sum/4;
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        
        vector<int> side_length(4,0);
        return solve(0,matchsticks,side_length,length);         
        
        return true;
    }
    
    bool solve(int cur, vector<int>& matchsticks, vector<int>& side_length, int length)
    {
        int n=matchsticks.size();
        if(cur==n) return (side_length[0]==side_length[1] && side_length[1]==side_length[2] && side_length[2]==side_length[3]);
        
        for(int i=0; i<4; ++i)
        {
            if(side_length[i]+matchsticks[cur]>length) continue;
            
            int index=i-1;
            while(index>0) 
            {
                if(side_length[index]==side_length[i]) break;
                --index;
            }
            if(index>0) continue;
            
            side_length[i]+=matchsticks[cur];
            
            if(solve(cur+1,matchsticks,side_length,length)) 
            { 
                //print(side_length); 
                return true; 
            }            
            //else print(side_length);
            
            side_length[i]-=matchsticks[cur];
        }
        
        return false;
    }
    
    /*void print(vector<int>& side_length)
    {
        for(int i=0; i<4; ++i)
        {
            cout<<side_length[i]<<" ";        
        }
        cout<<endl;
    }*/
};
