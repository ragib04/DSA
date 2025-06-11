class Solution {
  public:
  int solve(int i, int n, vector<int> &dp){
      if(i == n) return 1;
      if(i>n) return 0;
      
      if(dp[i] != -1) return dp[i];
      
      dp[i] = (solve(i+1, n, dp) + solve (i+2, n, dp));
      return dp[i];
  }
    int countWays(int n) {
        // your code here
        vector<int> dp(n+1, -1);
        int ans = solve(0, n, dp);
        return ans;
        
    }
};
