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

//2022-08-19
//time  : O(n)
//space : O(n)
class Solution {
public:
    bool isPossible(vector<int>& nums)
    {
        unordered_map<int,int> cnt,tail;
        for(auto& num:nums) ++cnt[num];
        //print(cnt);
        
        for(auto& num:nums)
        {
            if(cnt.find(num)==cnt.end()) continue;
             
            --cnt[num];
            if(cnt[num]==0) cnt.erase(num);
            
            if(tail.find(num-1)!=tail.end())
            {
                --tail[num-1];
                if(tail[num-1]==0) tail.erase(num-1);
                
                ++tail[num];
            }
            else if(cnt.find(num+1)!=cnt.end() && cnt.find(num+2)!=cnt.end())
            {
                    --cnt[num+1];
                    --cnt[num+2];
                    if(cnt[num+1]==0) cnt.erase(num+1);
                    if(cnt[num+2]==0) cnt.erase(num+2);
                    
                    ++tail[num+2];
            }
            else
            {
                return false;
            }
            
            //print(cnt);
        }
        
        return true;
    }
    
    void print(unordered_map<int,int>& m)
    {
        for(auto& i:m)
        {
            cout<<"("<<i.first<<","<<i.second<<") ";            
        }
        cout<<endl;
    }
};

//2022-08-19
//time  : O(n)
//space : O(1)
class Solution {
public:
    bool isPossible(vector<int>& nums)
    {
        int curNum=0, curLen1=0, curLen2=0, curLen3=0;
        int preNum=INT_MIN, preLen1=0, preLen2=0, preLen3=0;
        
        int n=nums.size();
        for(int i=0; i<n;)
        {
            curNum=nums[i];
            int count=0;
            while(i<n && curNum==nums[i])
            {
                ++count;
                ++i;
            }
            
            if(preNum+1!=curNum)
            {
                if(preLen1!=0 || preLen2!=0) return false;
                
                curLen1=count;
                curLen2=0;
                curLen3=0;                
            }
            else
            {
                if(count-preLen1-preLen2<0) return false;
                
                count-=preLen1;
                curLen2=preLen1;
                
                count-=preLen2;
                curLen3=preLen2+min(preLen3,count);
                
                count-=preLen3;
                curLen1=max(0,count);
                
                //cout<<count+preLen1+preLen2+preLen3<<" = "<<curLen1<<"+"<<curLen2<<"+"<<curLen3<<endl;
            }
            
            preNum=curNum;
            preLen1=curLen1;
            preLen2=curLen2;
            preLen3=curLen3;
        }
        
        return preLen1==0 && preLen2==0;
    }    
};
