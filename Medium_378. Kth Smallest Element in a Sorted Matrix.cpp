//2022-08-03
//min heap, like merge sorted K lists
//time  : O(nlogn*k)
//space : O(n)
class Solution 
{
private:
    struct item
    {
        int val;
        int row;
        int col;
        
        item(int v, int r, int c)
        {
            val=v;
            row=r;
            col=c;
        }
    };
    
    class comp
    {
    public:
        bool operator()(const item& a, const item& b)
        {
            return a.val > b.val;
        }
    };
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int n=matrix.size();
        if(k==n*n) return matrix[n-1][n-1];
        if(k==1) return matrix[0][0];
        
        priority_queue<item, vector<item>, comp> minHeap;
        
        for(int c=0; c<n; ++c)
        {
            //item tmp(matrix[0][c],0,c);
            //minHeap.push(tmp);
            minHeap.push(item(matrix[0][c],0,c));
        }
                
        while(k!=1)
        {
            //cout<<k<<" : "<< minHeap.top().val<<endl;
            int row=minHeap.top().row;
            int col=minHeap.top().col;
            minHeap.pop();
            
            if(row+1<n)
            {
                //item tmp(matrix[row+1][col],row+1,col);
                //minHeap.push(tmp);
                minHeap.push(item(matrix[row+1][col],row+1,col));
            }
            
            --k;
        }
                
        return minHeap.top().val;
    }
};
