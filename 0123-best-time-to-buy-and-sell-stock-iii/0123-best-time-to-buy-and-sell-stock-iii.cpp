class Solution {
public:

    long solve(int i, int buy, int cap, vector<int>& prices, int n,
           vector<vector<vector<int>>>& dp)
 {

          if(cap==0) return 0;
        if (i == n)
            return 0;

        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        long profit = 0;
        if (buy) {

            profit = max(-prices[i] + solve(i + 1, 0, cap, prices, n, dp),
                         0 + solve(i + 1, 1,cap, prices, n, dp));
        } else {
            profit = max(prices[i] + solve(i + 1, 1, cap-1, prices, n, dp),
                         0 + solve(i + 1, 0,cap, prices, n, dp));

                        

        }
           
        return dp[i][buy][cap] = profit;
           
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        //return solve(0, 1, 2, prices, n, dp);
        dp[n][0][0] = dp[n][1][0] = 0;
         for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy<=1; buy++){
                for(int cap= 1; cap<=2; cap++){

                  long profit = 0;
        if (buy) {

            profit = max(-prices[i] + dp[i + 1][0][cap],
                         0 + dp[i + 1][1][cap]);
        } else {
            profit = max(prices[i] + dp[i + 1][1][cap-1],
                         0 + dp[i + 1][0][cap]);
        }
        dp[i][buy][cap] = profit;
            }
            }
         }
         return dp[0][1][2];
    }
};