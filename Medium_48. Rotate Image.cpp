class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n=matrix.size()-1, m=matrix[0].size()-1;
        int len=n;
        
        for(int r=0; r<=len/2; ++r)
        {
            int offset=0;
            for(int c=r; c<m; ++c)
            {
                
                /*cout<<r<<" : "<<c<<endl;
                cout<<r+offset<<" "<<m<<endl;
                cout<<n<<" "<<m-offset<<endl;
                cout<<n-offset<<" "<<r<<endl<<endl;*/
                
                
                swap(matrix[r][c],matrix[r+offset][m]);
                swap(matrix[r][c],matrix[n][m-offset]);
                swap(matrix[r][c],matrix[n-offset][r]);
                
                ++offset;
            }
            
            --n;
            --m;
        }
    }
};
