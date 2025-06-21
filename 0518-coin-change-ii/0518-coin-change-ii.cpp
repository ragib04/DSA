class Solution {
public:

int func(int ind, int t,vector<int> &coins, vector<vector<long>> &dp){
    if(ind == 0){
        return (t%coins[0] == 0);
    }
    if(dp[ind][t] != -1) return dp[ind][t];

    long not_take = func(ind-1, t, coins, dp);
    long take = 0;
    if(coins[ind] <= t) take = func(ind, t-coins[ind], coins, dp);

    return dp[ind][t] = take + not_take;
}
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long>> dp(n, vector<long>(amount+1, 0));
        //return func(n-1, amount, coins, dp);
        //for(int i = 0; i<n; i++) dp[i][0] = 1;

        for(int i = 0; i<=amount; i++){
            if(i%coins[0] == 0) dp[0][i] = 1;
        }

        for(int i = 1; i<n; i++){
            for(int j = 0; j<=amount; j++){
                long pick = 0;
                long not_pick = dp[i-1][j];
                if(coins[i]<=j) pick = dp[i][j-coins[i]];
    dp[i][j] = (not_pick + pick > INT_MAX)? INT_MAX : not_pick+pick;

            }
        }
        return (int)dp[n-1][amount];
    }
};