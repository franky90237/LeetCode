//2022-10-19
//time  : O(n)
//space : O(1)
class Solution {
public:
    bool sumOfNumberAndReverse(int num) 
    {
        for(int i=0; i<=num; ++i)
        {
            int revI=reverse_int(i);
            if(i + revI == num) return true;
        }
        
        return false;
    }
    
    int reverse_int(int num)
    {
        int sum=0;
        while(num != 0)
        {
            sum = sum*10 + num%10;
            num /= 10;
        }
        
        return sum;
    }
};

//2022-10-19
//time  : O(n)
//space : O(1)
class Solution {
public:
    bool sumOfNumberAndReverse(int num) 
    {
        int revI;
        int increment=1;
        for(int i=0; i<=num; ++i)
        {
            if(i%10 == 0)
            {
                revI=reverse_int(i);
                if(revI == 1) increment *= 10;                
            }
            else
            {
                revI = revI + increment;
            }
            
            //cout<<i<<" "<<revI<<endl;
            if(i + revI == num) return true;
        }
        
        return false;
    }
    
    int reverse_int(int num)
    {
        int sum=0;
        while(num != 0)
        {
            sum = sum*10 + num%10;
            num /= 10;
        }
        
        return sum;
    }
};

//2022-11-03
//time  : O(n*n), n is the bank size
//spcae : O(n)
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if(bankSet.count(end) == 0) return -1;
        
        unordered_set<string> visited;
        queue<string> q;
        
        int ans=0;
        visited.insert(start);
        q.push(start);
        while(!q.empty())
        {
            int size=q.size();
            while(size > 0)
            {
                string cur=q.front();
                q.pop();
                if(cur == end) return ans;
                
                for(auto& gene: bankSet)
                {
                    if(visited.count(gene) == 0 && difference(cur, gene) == 1)
                    {
                        visited.insert(gene);
                        q.push(gene);
                    }
                }
                
                --size;
            }
            
            ++ans;
        }
                        
        return -1;
    }    
    
    int difference(const string& a, const string& b)
    {
        int diff=0;
        for(int i=0; i<a.size(); ++i)
        {
            if(a[i] != b[i])
            {
                ++diff;
                if(diff >= 2) break;
            }
        }
        
        return diff;
    }        
};
