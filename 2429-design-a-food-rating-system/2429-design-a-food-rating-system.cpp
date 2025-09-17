class FoodRatings {
public:

    unordered_map<string, string> food_cuisin;
    unordered_map<string, set<pair<int, string>>> cusin_rating_food;
    unordered_map<string, int> food_rating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i<n; i++){
            string food = foods[i];
            string cuisin = cuisines[i];
            int rating = ratings[i];

            cusin_rating_food[cuisin].insert({-rating, food});
            food_cuisin[food] = cuisin;
            food_rating[food] = rating;
        }
        
    }
    
    void changeRating(string food, int newRating) {
        string cuisin = food_cuisin[food];
        int oldRating = food_rating[food];

        food_rating[food] = newRating;
        cusin_rating_food[cuisin].erase({-oldRating, food});
        cusin_rating_food[cuisin].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return begin(cusin_rating_food[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */