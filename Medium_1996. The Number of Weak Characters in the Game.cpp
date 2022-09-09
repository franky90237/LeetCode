//2022-09-10
//time  : O(n)
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
