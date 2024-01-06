//2024-01-06
//time  : O(26*n + (log(n) + 26*6)*q)
//space : O(26*n)
class Solution 
{
private:
    vector<vector<int>> isSame;    
    vector<vector<int>> freqL;
    vector<vector<int>> freqR;
    
public:    
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) 
    {
        int n=s.size();        
        freqL.resize(n/2, vector<int>(26, 0));
        freqR.resize(n/2, vector<int>(26, 0));
        
        for(int left=n/2, right=n-1; left<right; ++left, --right)
        {
            swap(s[left], s[right]);
        }
        
        for(int i=0; i<n/2; ++i) 
        {        
            ++freqL[i][s[i]-'a'];
            if(i+1 < n/2) freqL[i+1]=freqL[i];
            //print(freqL[i]);
        }
        
        //cout<<endl;
        for(int i=n/2; i<n; ++i) 
        {            
            ++freqR[i-n/2][s[i]-'a'];
            if(i+1 < n) freqR[i+1-n/2]=freqR[i-n/2];
            //print(freqR[i-n/2]);
        }
        
        for(int i=0; i<26; ++i)
        {
            if(freqL[n/2-1][i] != freqR[n/2-1][i]) return vector<bool>(queries.size(), false);
        }            
                
        for(int i=0, k=n/2; i<n/2; ++i, ++k)
        {
            //cout<<i<<" "<<k<<endl;
            if(s[i] != s[k]) continue;
            
            int base=i;
            while(i < n/2 && s[i] == s[k])
            {
                ++i;
                ++k;
            }
            
            --i;
            --k;
            isSame.push_back({i, base});
        }
        
        //for(int i=0; i<isSame.size(); ++i) cout<<"("<<isSame[i][1]<<","<<isSame[i][0]<<") "; cout<<endl;
        
        //cout<<checkRangeSame(0, 3)<<endl;
        //cout<<checkRangeSame(0, 2)<<endl;
        //cout<<checkRangeSame(1, 1)<<endl;
        //cout<<checkRangeSame(0, 0)<<endl;        
        //cout<<"\ndone \n"<<endl;
        
        vector<bool> ans;
        for(auto& q : queries)
        {
            int a=q[0], b=q[1];
            int c=n-q[2]-1, d=n-q[3]-1;                        
            swap(c, d);
            
            bool res=true;
            if(a <= c)
            {
                res = checkL(a, b, c, d);
                ans.push_back(res);
            }
            else
            {
                res = checkR(c, d, a, b);
                ans.push_back(res);
            }
            
            //ans.push_back(res);
        }            
        
        return ans;
    }
    
    bool checkL(int a, int b, int c, int d)
    {
        //cout<<"(L) "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        int n=freqL.size();
        
        if(min(a, c)-1 >= 0 && !checkRangeSame(0, min(a, c)-1)) return false;
        if(max(b, d)+1 <= n-1 && !checkRangeSame(max(b, d)+1, n-1)) return false;        
        
        if(!Overlap(a, b, c, d))
        {
            /*
            |  |
                  |  |
            */                       
            
            if(!checkRangeSame(b+1, c-1)) return false;
            
            vector<int> left=getFreqL(a, b);
            vector<int> right=getFreqR(a, b);        
            bool res = minusFreq(left, right);
            if(!res) return false;
            
            left=getFreqL(c, d);
            right=getFreqR(c, d);        
            res = minusFreq(right, left);
            if(!res) return false; 
        }
        else
        {
            //cout<<"overlap (L) \n";
            if(!Cover(a, b, c, d))
            {
                /*
                |     |
                    |     |
                */
                
                //cout<<"not cover (L) \n";
                vector<int> left=getFreqL(a, b);
                vector<int> right=getFreqR(a, c-1);        
                bool res = minusFreq(left, right);
                //print(left);
                //print(right);
                if(!res) return false;
                
                left=getFreqL(b+1, d);
                right=getFreqR(c, d);        
                res = minusFreq(right, left);
                if(!res) return false;
            }
            else
            {
                /*
                |     |
                  | |
                */
                
                //cout<<"cover (L) \n";
                vector<int> left=getFreqL(a, b);
                //print(left);                
                vector<int> right1=getFreqR(a, c-1);
                vector<int> right2=getFreqR(d+1, b);
                //print(right1);
                //print(right2);
                addFreq(right1, right2);
                //print(right1);
                bool res = minusFreq(left, right1);
                if(!res) return false;            
            }
        }
        
        return true;
    }
    
    bool checkR(int a, int b, int c, int d)
    {
        //cout<<"(R) "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        int n=freqL.size();
        
        if(min(a, c)-1 >= 0 && !checkRangeSame(0, min(a, c)-1)) return false;
        if(max(b, d)+1 <= n-1 && !checkRangeSame(max(b, d)+1, n-1)) return false;        
        
        if(!Overlap(a, b, c, d))
        {
            /*
            |  |
                  |  |
            */
            
            if(!checkRangeSame(b+1, c-1)) return false;
            
            vector<int> left=getFreqR(a, b);
            vector<int> right=getFreqL(a, b);        
            bool res = minusFreq(left, right);
            if(!res) return false;
            
            left=getFreqR(c, d);
            right=getFreqL(c, d);        
            res = minusFreq(right, left);
            if(!res) return false; 
        }
        else
        {
            //cout<<"overlap (R) \n";
            if(!Cover(a, b, c, d))
            {
                /*
                |     |
                    |     |
                */
                
                vector<int> left=getFreqR(a, b);
                vector<int> right=getFreqL(a, c-1);        
                bool res = minusFreq(left, right);
                //print(left);
                //print(right);
                if(!res) return false;
                
                left=getFreqR(b+1, d);
                right=getFreqL(c, d);        
                res = minusFreq(right, left);
                if(!res) return false;
            }
            else
            {
                /*
                |     |
                  | |
                */
                
                //cout<<"cover (R) \n";
                vector<int> left=getFreqR(a, b);
                //print(left);
                vector<int> right1=getFreqL(a, c-1);
                vector<int> right2=getFreqL(d+1, b);
                //print(right1);
                //print(right2);
                addFreq(right1, right2);
                //print(right1);
                bool res = minusFreq(left, right1);
                if(!res) return false;            
            }
        }
        
        return true;
    }
           
    bool checkRangeSame(int left, int right)
    {
        if(left > right) return true;
        //cout<<left<<" "<<right<<" | "<<endl;
        
        auto it=lower_bound(isSame.begin(), isSame.end(), right, [](vector<int>& a, int b)
                            {                            
                                return a[0] < b;
                            });
        if(it == isSame.end()) return false;
        
        //cout<<left<<" "<<right<<" | ";
        //cout<<(*it)[1]<<" "<<(*it)[0]<<endl;
        int boundLeft=(*it)[1];
        return boundLeft <= left;
    }
           
    vector<int> getFreqL(int left, int right)
    {
        if(left > right) return vector<int>(26, 0);
        if(left == 0) return freqL[right];
        
        vector<int> res(26);
        for(int i=0; i<26; ++i) res[i]=freqL[right][i]-freqL[left-1][i];
        return res;
    }
    
    vector<int> getFreqR(int left, int right)
    {
        if(left > right) return vector<int>(26, 0);
        if(left == 0) return freqR[right];
        
        vector<int> res(26);
        for(int i=0; i<26; ++i) res[i]=freqR[right][i]-freqR[left-1][i];
        return res;
    }    
    
    bool minusFreq(vector<int>& lhs, vector<int> rhs)
    {
        for(int i=0; i<26; ++i)
        {
            if(lhs[i] - rhs[i] < 0) return false;
        }
        
        return true;
    }
    
    void addFreq(vector<int>& lhs, vector<int> rhs)
    {
        for(int i=0; i<26; ++i)
        {
            lhs[i] += rhs[i];
        }        
    }
    
    bool Overlap(int a, int b, int c, int d)
    {
        return b >= c;
    }
    
    bool Cover(int a, int b, int c, int d)
    {
        return a<=c && b>=d;
    }
    
    template<typename T>
    void print(vector<T>& arr)
    {
        for(auto i : arr) cout<<i<<" ";
        cout<<endl;
    }
};
