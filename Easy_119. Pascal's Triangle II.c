class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> result[2];
        result[0]=vector<int>(rowIndex+1);
        result[1]=vector<int>(rowIndex+1);
        
        result[0][0]=1;
        for(int i=1;i<=rowIndex;++i)
        {
            result[i%2][0]=1;
            for(int j=1;j<rowIndex;++j)
            {
                result[i%2][j]=result[(i+1)%2][j-1]+result[(i+1)%2][j];
            }
            result[i%2][rowIndex]=1;
        }
        
        return result[rowIndex%2];
    }
};
