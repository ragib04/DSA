class Solution {

public:

int n;
int func(int ind, vector<vector<int>> &event, int k, vector<vector<int>> &dp){
    if(k == 0 || ind>=n) return 0;

    int start = event[ind][0];
    int end = event[ind][1];
    int value = event[ind][2];
if(dp[ind][k] != -1) return dp[ind][k];

    int not_take = func(ind+1, event, k, dp);
    int j = ind+1;
    for( ; j<n; j++){
        if(event[j][0]>end) break;
    }
    int take = value + func(j, event, k-1, dp);

    return dp[ind][k] = max(take, not_take);
}
    int maxValue(vector<vector<int>>& events, int k) {
      n = events.size();
        //if(k>n) return 0;
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        sort(events.begin(), events.end());
        return func(0,events, k, dp);

    }
};