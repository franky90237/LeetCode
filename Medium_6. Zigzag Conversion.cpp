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
