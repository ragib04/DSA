class Solution {
public:
int solve(int curr, int n, vector<int> &dp){
    if(curr == n) return 1;
    if(curr>n) return 0;
    if(dp[curr] != -1) return dp[curr];
    dp[curr] = solve(curr+1, n, dp) + solve(curr+2, n, dp);
    return dp[curr];
}
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        int ans = solve(0,n,dp);
        return ans;
    }
};