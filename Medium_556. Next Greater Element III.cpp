//2023-09-02
//time   : O(digit of n)
//space  : O(digit of n)
class Solution {
public:
    int nextGreaterElement(int n) 
    {
        int original=n;
        vector<int> num;
        while(n > 0)
        {
            num.push_back(n%10);
            n/=10;
        }
        
        reverse(num.begin(), num.end());
        //for(auto i: num) cout<<i; cout<<endl;
        next_permutation(num.begin(), num.end());
        //for(auto i: num) cout<<i; cout<<endl;
        
        long greater=0;
        for(int i=0; i<num.size(); ++i)
        {
            greater = greater*10 + num[i];
        }
        
        //cout<<greater<<" "<<n<<endl;
        if(greater > INT_MAX || greater <= original) return -1;
        return greater;
    }
};
