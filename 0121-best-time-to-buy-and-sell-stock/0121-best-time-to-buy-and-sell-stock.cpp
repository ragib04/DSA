class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buy = prices[0];
        for(int i = 1; i<prices.size(); i++){
            int profit = prices[i]-buy;
            max_profit = max(profit, max_profit);
            if(buy>prices[i]) buy = prices[i];
        }
        return max_profit;

    }
};