//2022-09-15
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed)
    {
        /*
        [1,2,3,4,6,8]
        
        8*2 = 16 -> 8
        6*2 = 12 -> 6
        4*2 = 8  -> X
        3*2 = 6  -> X
        2*2 = 4  -> X
        1*2 = 2  -> X
        
        [1,2,3,4] 6,8
        [1,2] (3,6) (4,8)
        
        [0,1,3,6]
        
        [2,4,6,8, 4,8,12,16]
        
        [2,4,4,6,8,8,12,16]
        
        [2,4,4,6,8,8] 12,16
        [2,4,4,8]  (6,12) (8,16)
        
        [2,4,4] 8
        [2,4] (4,8)
        
        [2,4,6,8,4,8,12,16]
        
        (2,4) (4,8) (6,12) (8,16)
        
        [2,4,6,8,4,8,12,16]
        (2,1) (4,2) (6,1) (8,2) (12,1) (16,1)
        
        2 : (2,0) (4,1) (6,1) (8,2) (12,1) (16,1)
        4 : (2,0) (4,0) (6,1) (8,1) (12,1) (16,1)
        6 : (2,0) (4,0) (6,0) (8,1) (12,0) (16,1)
        
        [2,2,2,2,4,4,4,4]
        
        (2,4) (4,4)
        2 : (2,3) (4,4)
        2 :
        
        [1,2,2,4]
        
        [1,2,4,8]
        
        [1,2,5,10,100,200]
        
        */
        vector<int> ans;
        
        map<int,int> table;
        for(auto& num:changed) ++table[num];
        
        if(table.find(0)!=table.end())
        {
            if(table[0]%2==1) return {};
            
            int cnt=table[0]/2;            
            for(int i=0; i<cnt; ++i) ans.push_back(0);
            table.erase(0);
        }
        
        for(auto& it:table)
        {
            //cout<<it.first<<endl;
            if(it.second < 0) continue;
            
            int num=it.first;
            
            while(it.second > 0)
            {
                int cnt=it.second;                
                
                int twice=2*num;
                if(table.find(twice)!=table.end() && table[twice] > 0)
                {
                    ans.push_back(num);
                    
                    --table[twice];
                    --it.second;
                }                
                
                if(it.second==cnt) return {};
            }
        }
        
        return ans;
    }
};
