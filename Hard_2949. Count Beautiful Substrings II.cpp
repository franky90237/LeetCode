//2023-11-29
//time  : O(k*k)
//space : O(n+k)
class Solution {
public:
    long long beautifulSubstrings(string s, int k) 
    {
        const int threshold = 1000;
        int n = s.size();        
        
        unordered_map<int, vector<int>> prefix;
        prefix[0].push_back(0);
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if(isVowel(s[i])) ++sum;
            else --sum;
            
            prefix[sum].push_back(i+1);
        }
        
        long long cnt = 0;
        for (auto& it : prefix)
        {
            //cout << it.first << endl;
            vector<int>& groups = it.second;
            int size = groups.size();
            if (size > threshold)
            {
                vector<int> table(k);
                for (int i = 0; i < size; ++i)
                {				
                    int val = (groups[i] / 2) % k;
                    for (int left = 0; left < k; ++left)
                    {					
                        int base = (val - left + k) % k;
                        if (table[left] > 0 && (base * base) % k == 0)
                        {
                            //cout << groups[i] << " | " << left << " " << val << " : " << base << endl;
                            cnt += table[left];
                        }
                    }

                    ++table[val];
                }                
            }
            else
            {
                for (int right = 0; right < size; ++right)
                {
                    for (int left = 0; left < right; ++left)
                    {
                        int base = (groups[right] - groups[left]) / 2;
                        if ((base * base) % k == 0)
                        {
                            //cout << groups[right] << " " << groups[left] << endl;
                            ++cnt;
                        }
                    }
                }
            }
        }
        
        return cnt;
    }
    
    bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};
