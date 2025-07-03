class Solution {
public:

int solve(int i, int buy, int n, vector<int> &prices, vector<vector<long>> &dp){
    if(i >= n) return 0;
    if(dp[i][buy] != -1) return dp[i][buy];
long profit = 0;
    if(buy){
        profit = max(-prices[i] + solve(i+1, 0, n, prices, dp), solve(i+1, 1, n, prices, dp));
    }
    else{
        profit = max(prices[i]+solve(i+2, 1, n, prices, dp), solve(i+1, 0, n, prices, dp));
    }
    return dp[i][buy] = profit;

}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n, vector<long>(2, -1));
        return solve(0, 1, n, prices, dp);
    }
};