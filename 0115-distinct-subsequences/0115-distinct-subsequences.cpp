class Solution {
public:
    int func(int i, int j, string s, string t, vector<vector<int>>& dp) {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] =
                       func(i - 1, j - 1, s, t, dp) + func(i - 1, j, s, t, dp);
        else
            return dp[i][j] = func(i - 1, j, s, t, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        //vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
        // return func(n - 1, m - 1, s, t, dp);
        vector<double> prev(m+1, 0), curr(m+1,0);
      prev[0] = curr[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j - 1] + prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return (int)prev[m];
    }
};