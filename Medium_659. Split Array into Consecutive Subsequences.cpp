//2022-08-19
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    bool isPossible(vector<int>& nums)
    {
        /*
        1,2,3,4,5,6        
        1:{1} 2:{2} 3:{3} 4:{4} 5:{5} 6:{6}          
        
        1,2,3,3,4,5  
        1:{1} 2:{2} 3:{3} 3:{3,1} 3:{3}
        4:{2} 5:{3}
        
        1,2,3,3,4,4,5,5
        1:{1} 2:{2} 3:{3} 3:{3,1} 3:{3} 3:{} clear
        4:{2} 4:{2,4} 4:{4} 4:{} clear
        5:{3} 5:{3,5}
        
        1:{1} 2:{2} 3:{3,1} 3{3}
        4:{2,4} 4:{4} 5:{5}
        5:{3}
        
        1,2,3,4,5,6,6
        1:{1} 2:{2} 3:{3} 4:{4} 5:{5} 6:{6,1}         
        
        1,1,1,1
        1:{1} 1:{1,1} 1:{1,1,1} 1:{1,1,1,1}
        
        1,1,1,1,2,2,2,3,3,3
        1:{1} 1:{1,1} 1:{1,1,1} 1:{1,1,1,1} 1:{1,1,1} 1:{1,1} 1:{1}
        2:{2} 2:{2,2} 2:{2,2,2} 2:{2,2} 2:{2} 2:{} clear
        3:{3} 3:{3,3} 3:{3,3,3}
        */                
        
        int n=nums.size();    
        
        unordered_map<int,multiset<int>> subseq;
        subseq[nums[0]].insert(1);
        
        for(int i=1; i<n; ++i)
        {
            int num=nums[i];

            if(subseq.find(num-1)==subseq.end())
            {
                subseq[num].insert(1);
            }
            else
            {
                auto it=subseq[num-1].begin();
                int len=*it;

                if(subseq[num-1].size()==1) subseq.erase(num-1);
                else subseq[num-1].erase(it);

                subseq[num].insert(len+1);
            }            
        }
        
        //print(subseq);
        
        for(auto& num:subseq)
        {        
            for(auto& cnt:num.second)
            {                
                if(cnt<=2) return false;
            }            
        }
        
        return true;
    }
    
    void print(unordered_map<int,multiset<int>>& subseq)
    {
        for(auto& num:subseq)
        {
            cout<<num.first<<" : ";
            for(auto& cnt:num.second) cout<<cnt<<" ";            
            cout<<endl;
        }
        cout<<endl;
    }
};
