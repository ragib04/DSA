class Solution {
public:
// int solve(int n, vector<int> &cost, vector<int> &dp){
//     if(n<=1) return cost[n];

//     if(dp[n] != -1) return dp[n];

//     dp[n] = min(solve(n-1, cost, dp), solve(n-2, cost, dp)) + cost[n];
//     return dp[n];
// }

int solve2(int n, vector<int> &cost){
    vector<int> dp(n+1);

    int prev2 = cost[0];
    int prev1 = cost[1];

    for(int i = 2; i<n; i++){
        int curr = min(prev1, prev2) + cost[i];
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);
}

    int minCostClimbingStairs(vector<int>& cost) {
        // int n = cost.size();
        // vector<int> dp(n+1);
        // int ans = min(solve(n-1, cost, dp), solve(n-2, cost, dp));
        // return ans;

        //tabulation
        int n = cost.size();
        return solve2(n, cost);
    }
};