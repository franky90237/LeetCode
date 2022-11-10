//2022-11-10
//time  : O(n*n)
//sapce : O(n)
class StockSpanner 
{
private:    
    vector<vector<int>> stock;
public:
    StockSpanner() 
    {

    }
    
    int next(int price) 
    {
        int cur=stock.size();
        int pre=cur-1;
        while(pre >= 0 && stock[pre][0] <= price)
        {
            pre=pre-stock[pre][1];
        }

        stock.push_back({price, cur-pre});
        return cur-pre;
    }
};

//2022-11-10
//time  : O(n)
//sapce : O(n)
class StockSpanner 
{
private:
    int day;
    vector<vector<int>> stock;
    
public:
    StockSpanner() 
    {
        day=0;
    }
    
    int next(int price) 
    {        
        while(!stock.empty() && stock.back()[0] <= price)
        {
            stock.pop_back();
        }

        ++day;
        int span = (stock.empty()) ? day : day-stock.back()[1];
        stock.push_back({price, day});        
        return span;
    }
};
