/*

class Solution {
public:

int f(int ind, int t, vector<int> &coins, vector<vector<int>> &dp){
    if(ind == 0){
        if(t%coins[ind] == 0) return (t/coins[ind]);
        else return 1e9;

    }
    if(dp[ind][t] != -1) return dp[ind][t];

    int not_take = 0+ f(ind-1, t, coins, dp);
    int take = INT_MAX;
    if(t >= coins[ind]) take = 1 + f(ind, t-coins[ind], coins, dp);

    return dp[ind][t] = min(take, not_take);
}
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = f(n-1, amount, coins, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};
*/
/*
class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        int n = coins.size();
        vector<vector<int> > dp(n, vector<int> (target+1, 0));
        for(int t = 0; t<=target; t++){
            if(t%coins[0] == 0) dp[0][t] = t/coins[0];
            else dp[0][t] = 1e9;

        }
        for(int ind = 1; ind<n; ind++){
            for(int t = 0; t<=target; target++){
                int not_take = dp[ind-1][t];
                int take = INT_MAX;
                if(t>=coins[ind]) take = dp[ind][target-coins[ind]];

                dp[ind][t] = min(take, not_take);

            }
        }
        int ans = dp[n-1][target];
        if(ans >= 1e9) return -1;
        return ans;
    }
};
*/

// class Solution {
// public:
//     int coinChange(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<int> prev(target+1, 0), curr(target+1, 0);
//         for(int t = 0; t<=target; t++){
//             if(t%nums[0] == 0) prev[t] = t/nums[0];
//             else prev[t] = 1e9;
//         }
//         for (int ind = 1; ind<n; ind++){
//             for(int t = 0; t<=target;t++){
//                 int not_take = 0 + prev[t];
//                 int take = 1e9;
//                 if(nums[ind] <= t) take = 1 + curr[t-nums[ind]];

//                 curr[t] = min(take, not_take);
//             }
//             prev = curr;
//         }
//         int ans = prev[target];
//         if(ans >= 1e9) return -1;

//         return ans;
//     }
// };


class Solution {
public:
int solve(int i, int amnt, vector<int> &coins, vector<vector<int>> &dp){
    if(i == 0){
        if(amnt%coins[i] == 0) return amnt/coins[i];
        else return 1e9;

    }
    if(dp[i][amnt] != -1) return dp[i][amnt];
    int not_take = solve(i-1, amnt, coins, dp);
    int take  = INT_MAX;
    if(amnt>=coins[i]){
        take = 1 + solve(i, amnt-coins[i], coins, dp);
    }

    return dp[i][amnt] = min(take, not_take);
    
}
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans  = solve(n-1, amount, coins, dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};