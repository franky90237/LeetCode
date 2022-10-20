//2022-10-20
//time  : O(n)
//space : O(1)
class Solution {
public:
    string intToRoman(int num) 
    {
        unordered_map<int, char> table;
        table=
        {
            {1, 'I'},
            {5, 'V'},
            {10, 'X'},
            {50, 'L'},
            {100, 'C'},
            {500, 'D'},
            {1000, 'M'}
        };
        
        string ans;
        int digit=(float)log(num)/(float)log(10);
        int power=pow(10, digit);
        while(power != 0)
        {
            int q=num/power;
            
            if(q == 4 || q == 9)
            {
                ans.push_back(table[power]);
                ans.push_back(table[power*(q+1)]);
            }
            else if(q == 5)
            {
                ans.push_back(table[power*5]);
            }
            else if(q < 4)
            {
                string tmp(q, table[power]);                
                ans+=tmp;
            }
            else
            {
                string tmp(q-5, table[power]);
                ans.push_back(table[power*5]);
                ans+=tmp;
            }
            
            //cout<<q<<" "<<power<<" : "<<ans<<endl;
            num %= power;
            power /= 10;
        }
        
        return ans;
    }
};

/*
1994/1000 = 1
994/100= 9
94/10=9
4/1=4
0
*/
