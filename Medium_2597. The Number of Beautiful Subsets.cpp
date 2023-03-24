//2023-03-23
//time  : O(nlog(n))
//space : O(n+k)
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k)
    {
        vector<map<int, int>> group(k);        
        
        for(auto num: nums)
        {
            ++group[num % k][num];            
        }
        
        //int ans=1;
        int pick=0;
        int not_pick=0;
        
        for(int i=0; i<k; ++i)
        {
            if(group[i].empty()) continue;                        
            
            auto head=group[i].begin();
            int preNum=(head->first)-k-1;
            
            
            for(auto& it: group[i])
            {
                int num=it.first;
                int cnt_of_num=it.second;                
                int cnt_of_subset=pow(2, cnt_of_num)-1;
                    
                if(num-preNum == k)
                {
                    int pre_not_pick=not_pick;
                    
                    not_pick += pick;
                    pick=(pre_not_pick+1)*cnt_of_subset;
                }
                else
                {
                    int pre_not_pick=not_pick;
                    
                    not_pick += pick;
                    pick=(pick+pre_not_pick+1)*cnt_of_subset;
                }
                
                preNum=num;
                //cout<<num<<" | "<<pick<<" "<<not_pick<<endl;
            }                        
        }
        
        return pick+not_pick;
    }
};
