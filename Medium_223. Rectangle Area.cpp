//2022-11-18
//time  : O(1)
//space : O(1)
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) 
    {
        vector<vector<int>> x;
        x.push_back({ax1, ax2});
        x.push_back({bx1, bx2});
        
        vector<vector<int>> y;
        y.push_back({ay1, ay2});
        y.push_back({by1, by2});
        
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());                      
        
        int area1=(ax2-ax1)*(ay2-ay1);
        int area2=(bx2-bx1)*(by2-by1);
        if(x[0][1] <= x[1][0] || y[0][1] <= y[1][0])
        {
            return area1+area2;
        }
        
        int cx1=max(ax1, bx1);
        int cy1=max(ay1, by1);
        int cx2=min(ax2, bx2);
        int cy2=min(ay2, by2);
        int area3=(cx2-cx1)*(cy2-cy1);
        
        //cout<<area1<<" "<<area2<<" "<<area3<<endl;
        
        return area1+area2-area3;
    }
};
