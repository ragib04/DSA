class Solution {
public:
int solve(int currstair, int n, vector<int> &dp){
    if(currstair == n) return 1;
    if(currstair > n) return 0;
    if(dp[currstair] != -1) return dp[currstair];

    dp[currstair] = solve(currstair+1, n, dp) + solve(currstair+2, n, dp);
    return dp[currstair];
}
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(0,n,dp);
    }
};