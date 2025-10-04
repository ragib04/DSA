class Solution {
public:
int solve(int n, int i, vector<int> &dp){
    if(i == n) return 1;
    if(i >n) return 0;
    if(dp[i] != -1) return dp[i];

    dp[i] = solve(n, i+1, dp) + solve(n, i+2, dp);
    return dp[i];
}
    int climbStairs(int n) {
        // vector<int> dp(n+1, -1);
        // return solve(n, 0, dp);
        if(n==2) return n;
        if(n<2) return 1;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i<=n; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};