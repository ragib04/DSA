// for buy/ take = -prices[i] + solve(i + 1, 0, prices, n, dp)
// for not take = 0 + solve(i + 1, 1, prices, n, dp));
//for sale = prices[i] + solve(i + 1, 1, prices, n, dp),
// you not sale =  0 + solve(i + 1, 0, prices, n, dp));

class Solution {
public:
    long solve(int i, int buy, vector<int>& prices, int n,
               vector<vector<int>>& dp) {
        if (i == n)
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        long profit = 0;
        if (buy) {

            profit = max(-prices[i] + solve(i + 1, 0, prices, n, dp),
                         0 + solve(i + 1, 1, prices, n, dp));
        } else {
            profit = max(prices[i] + solve(i + 1, 1, prices, n, dp),
                         0 + solve(i + 1, 0, prices, n, dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       // vector<vector<int>> dp(n, vector<int>(2, -1));
        //return solve(0, 1, prices, n, dp);

         vector<vector<long>> dp(n+1, vector<long>(2, 0));
         dp[n][0] = dp[n][1] = 0;
         for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy<=1; buy++){
                  long profit = 0;
        if (buy) {

            profit = max(-prices[i] + dp[i + 1][0],
                         0 + dp[i + 1][1]);
        } else {
            profit = max(prices[i] + dp[i + 1][1],
                         0 + dp[i + 1][0]);
        }
        dp[i][buy] = profit;
            }
         }
         return dp[0][1];
    }
};