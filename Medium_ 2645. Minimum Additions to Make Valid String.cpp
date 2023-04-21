//2023-04-16
//time  : O(n)
//space : O(1)
class Solution {
public:
    int addMinimum(string word) 
    {
        int n=word.size();
        int ans=0;
        for(int i=0; i<n; ++i)
        {
            char c=word[i];
            if(c == 'c')
            {
                ans += 2;
            }
            else if(c == 'b')
            {
                ++ans;
                if(i+1 >= n || word[i+1] != 'c')
                {
                    ++ans;
                    continue;
                }
                
                ++i;
            }
            else
            {                
                if(i+1 >= n)
                {
                    ans += 2;
                    break;
                }
                char nc=word[i+1];
                if(nc == 'c') //ac
                {
                    ++ans;
                    ++i;
                    continue;
                }
                else if(nc == 'a') //aa
                {
                    ans += 2;                    
                    continue;
                }
                
                ++i;
                if(i+1 >= n)
                {
                    ++ans;
                    break;
                }
                char nnc=word[i+1];
                if(nnc == 'c') //abc
                {
                    ++i;
                }
                else //abb or aba
                {
                    ans += 1;                    
                }
            }
        }
        
        return ans;
    }
};

//2023-04-21
//time  : O(n)
//spcae : O(1)
class Solution {
public:
    int addMinimum(string word) 
    {
        char pre='c';
        int ans=0;
        for(auto c: word)
        {
            //a b
            //a c
            //b c
            if(c > pre)
            {
                pre = c;
                continue;
            }
            
            pre = c;
            ++ans;
        }
                
        return 3*ans - (int)word.size();
    }
};

//2023-04-21
//time  : O(n)
//spcae : O(1)
class Solution {
public:
    int addMinimum(string word) 
    {
        int n=word.size();
        int ans=0;
        int i=0;
        while(i < n)
        {
            if(word[i] != 'a')
            {
                ++ans;
            }
            else 
            {
                ++i;                
            }
            
            if(i >= n || word[i] != 'b')
            {
                ++ans;
            }
            else
            {
                ++i;
            }
            
            if(i >= n || word[i] != 'c')
            {
                ++ans;
            }
            else
            {
                ++i;
            }
        }
        
        return ans;
    }
};
