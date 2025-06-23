// User function Template for C++

class Solution {
  public:
  
  int f(int ind, int w, vector<int> &val, vector<int>&wt, vector<vector<int>> &dp){
    if(ind == 0){
        return (w/wt[ind]*val[ind]);
    }
    if(dp[ind][w] != -1) return dp[ind][w];
    int not_pick = 0+f(ind-1, w, val, wt, dp);
    int pick = INT_MIN;
    if(w>= wt[ind]){
        pick = val[ind]+ f(ind, w-wt[ind], val, wt, dp);

    }

    return dp[ind][w] = max(pick, not_pick);
}
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
        return f(n-1, capacity, val, wt, dp);
        
    }
};