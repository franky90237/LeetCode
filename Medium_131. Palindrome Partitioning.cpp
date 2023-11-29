//2023-11-29
//time  : O(2^n)
//space : O(n)
class Solution 
{
private:
    vector<vector<string>> ans;
    vector<string> cur;
    
public:
    vector<vector<string>> partition(string s) 
    {
        solve(s, 0);
        return ans;
    }
    
    void solve(string& s, int idx)
    {
        int n=s.size();
        if(idx >= n) 
        {
            ans.push_back(cur);
            return;
        }
        
        for(int i=idx; i<n; ++i)
        {
            if(isPalindrome(s, idx, i))
            {
                string tmp=s.substr(idx, i-idx+1);
                cur.push_back(tmp);
                solve(s, i+1);
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& s, int left, int right)
    {
        while(left < right)
        {
            if(s[left] != s[right]) return false;
            ++left;
            --right;
        }
        
        return true;
    }
};

//2023-11-29
//time  : O(2^n)
//space : O(n)
class Solution 
{
private:
    vector<vector<string>> ans;
    vector<string> cur;
    
public:
    vector<vector<string>> partition(string s) 
    {
        solve(s, 0, 0);
        return ans;
    }
    
    void solve(string& s, int begin, int end)
    {
        int n = s.size();
        if (end >= n)
        {
            if (begin < n && isValid(s, begin, end-1))
            {
                //cout << begin << " " << end - 1 << endl;
                cur.push_back(s.substr(begin, end - begin));
                ans.push_back(cur);
                cur.pop_back();
            }

            return;
        }
        
        solve(s, begin, end + 1);

        if (isValid(s, begin, end))
        {
            cur.push_back(s.substr(begin, end - begin + 1));
            solve(s, end + 1, end + 1);
            cur.pop_back();
        }
    }

    bool isValid(string& s, int left, int right)
    {
        //if (left > right) return false;
        
        while (left < right)
        {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        
        return true;
    }
};
