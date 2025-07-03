class Solution {
public:

 long solve(int i, int buy, vector<int>& prices, int n,
               vector<vector<int>>& dp, int fee) {
        if (i == n)
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        long profit = 0;
        if (buy) {

            profit = max(-prices[i] + solve(i + 1, 0, prices, n, dp, fee),
                         0 + solve(i + 1, 1, prices, n, dp, fee));
        } else {
            profit = max(prices[i] + solve(i + 1, 1, prices, n, dp, fee) -fee,
                         0 + solve(i + 1, 0, prices, n, dp, fee));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
         int n = prices.size();
       vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, n, dp, fee);
    }
};