// User function Template for C++

class Solution {
  public:
  int f(int ind, vector<int> &val, int n, vector<vector<int>> &dp){
    if(ind == 0){
        return (n*val[0]);
    }
    if(dp[ind][n] != -1) return dp[ind][n];
    int not_pick = 0+f(ind-1, val, n, dp);
    int pick = INT_MIN;
    int rodlen = ind+1;
    if(rodlen<= n){
        pick = val[ind]+ f(ind, val,n-rodlen, dp);

    }

    return dp[ind][n] = max(pick, not_pick);
  }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(n-1, price,n,dp);
        
        
    }
};