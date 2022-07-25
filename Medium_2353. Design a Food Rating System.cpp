//2022-07-25
//time  : O(n)
//space : O(7*n)
class FoodRatings 
{
private:
    unordered_map<string,int> food_rating; 
    unordered_map<string,string> food_cuisine;
    unordered_map<string, set<pair<int,string>>> table;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) 
    {
        for(int i=0; i<foods.size(); ++i)
        {
            food_rating[foods[i]]=ratings[i];
            food_cuisine[foods[i]]=cuisines[i];
            table[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) 
    {
        int oldRating=food_rating[food];
        string cuisine=food_cuisine[food];
        
        food_rating[food]=newRating;
        table[cuisine].erase({-oldRating,food});
        table[cuisine].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) 
    {
        return (table[cuisine].begin())->second;
    }
};
