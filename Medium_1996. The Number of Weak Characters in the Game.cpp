//2022-09-10
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties)
    {
        /*
        [1,2,2,2,3,3,3]
        [5,3,2,1,9,8,7]
        */
        
        sort(properties.begin(),properties.end(),
            [](vector<int>& a, vector<int>& b)
             {
                 if(a[0]==b[0]) return a[1]>b[1];
                 return a[0]<b[0];
             });
        
        int ans=0;
        stack<int> mono_stack;        
        for(auto& property:properties)
        {
            while(!mono_stack.empty() && mono_stack.top()<property[1])
            {
                mono_stack.pop();
                ++ans;
            }
            
            mono_stack.push(property[1]);
        }
        
        return ans;
    }
};

//2022-09-10
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties)
    {
        /*
        [1,2,2,2,3,3,3]
        [5,9,3,2,6,5,4]
        */
        
        sort(properties.begin(),properties.end(),
            [](vector<int>& a, vector<int>& b)
             {
                 if(a[0]==b[0]) return a[1]>b[1];
                 return a[0]<b[0];
             });
        
        int ans=0;
        int max_defense=INT_MIN;    
        for(int i=properties.size()-1; i>=0; --i)
        {
            if(max_defense>properties[i][1])
            {            
                ++ans;
            }
            else
            {
                max_defense=properties[i][1];
            }
        }
        
        return ans;
    }
};

//2022-09-10
//time  : O(n+k), k is the range of attack
//space : O(1)
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties)
    {        
        const int SIZE=100000;
        int group[SIZE+2]={0};
        
        for(auto& p:properties)
        {
            int attack=p[0];
            int defense=p[1];
            
            group[attack]=max(group[attack],p[1]);
        }
                    
        for(int i=SIZE; i>=0; --i)
        {            
            group[i]=max(group[i],group[i+1]);
        }
        
        int ans=0;
        for(auto& p:properties)
        {
            int attack=p[0];
            int defense=p[1];
            if(defense<group[attack+1]) ++ans;
        }
        
        return ans;
    }
};
