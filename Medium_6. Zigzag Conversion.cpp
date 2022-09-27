//2022-09-27
//time  : O(n*m), m is the row size
//space : O(n*m), m is the row size
class Solution {
public:
    string convert(string s, int numRows) 
    {
        /*
        14/6=2..2
        "PAYP A L ISHIRING"

        col[0]=PAYP
        col[1]=??A?
        col[2]=?L??
        col[3]=ISHI
        */
        
        if(numRows==1) return s;
        
        int n=s.size();
        
        vector<string> col;
        int i=0;
        while(i < n)
        {
            int cnt = col.size() % (numRows-1);
            if(cnt == 0)
            {
                col.push_back({});
                
                int k=i;
                while(k<i+numRows && k < n)
                {
                    col.back().push_back(s[k]);
                    ++k;
                }
                
                i=k;
            }
            else
            {
                string tmp(numRows, ' ');
                tmp[numRows-1-cnt]=s[i];
                col.push_back(tmp);
                
                ++i;
            }
        }
        
        //for(auto& str : col) cout<<str<<endl;        
        
        string ans;
        for(int row=0; row<numRows; ++row)
        {
            for(auto& str : col)
            {
                //cout<<str[row];
                if(str.size() > row && str[row] != ' ') ans.push_back(str[row]);
            }
            //cout<<endl;
        }
        
        return ans;
    }
};

//2022-09-27
//time  : O(n)
//space : O(n)
class Solution {
public:
    string convert(string s, int numRows) 
    {
        /*
        0   4   8     12...
        1 3 5 7 9  11
        2   6   10

        0    6      12
        1  5 7   11 13
        2 4  8 10   14
        3    9      15

        1 (1+2+2)=5 5+1+1=7  7+2+2
        2 (2+1+1)=4 

        1 (7-1-1)=5
        2 (8-2-2)=4

        0     8 
        1   7 9
        2  6  10
        3 5   11
        4     12 
        */
        
        if(numRows==1) return s;
        
        int n=s.size();
        string ans(n, ' ');
        
        int increment=numRows+numRows-2;
        int idx_actual=0;
        
        for(int i=0; i<n; i+=increment)
        {
            ans[idx_actual]=s[i];
            ++idx_actual;
        }
               
        for(int r=1; r<numRows-1; ++r)
        {
            for(int i=r; i<n; i+=increment)
            {
                ans[idx_actual]=s[i];
                ++idx_actual;
                
                int next=i + 2*(numRows-(i%increment)-1);
                if(next < n) 
                {
                    ans[idx_actual]=s[next];
                    ++idx_actual;
                }
                
                //cout<<ans<<endl;
            }
            
        }
        
        for(int i=numRows-1; i<n; i+=increment)
        {
            ans[idx_actual]=s[i];
            ++idx_actual;
        }
        
        return ans;
    }    
};

//2022-09-27
//time  : O(n)
//space : O(n)
class Solution {
public:
    string convert(string s, int numRows) 
    {        
        if(numRows==1) return s;
        
        int n=s.size();
        
        vector<string> row(numRows);
        bool goingDown=false;
        int r=0;
        for(int i=0; i<n; ++i)
        {
            row[r].push_back(s[i]);
            
            if(r==0 || r==numRows-1) goingDown = !goingDown;
            if(goingDown) ++r;
            else --r;
        }
        
        int i=0;
        for(r=0; r<row.size(); ++r)
        {
            for(auto& c: row[r])
            {
                s[i]=c;
                ++i;
            }
            //cout<<row[r]<<endl;
        }
        
        return s;
    }    
};
