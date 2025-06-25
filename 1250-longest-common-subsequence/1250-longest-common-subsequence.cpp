class Solution {
public:
    int solve(int i, int j, string& x, string& y, vector<vector<int>>& dp) {
        if (i == x.size() || j == y.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if (x[i] == y[j]) {
            ans = 1 + solve(i + 1, j + 1, x, y, dp);
        } else {
            ans = max(solve(i + 1, j, x, y, dp), solve(i, j + 1, x, y, dp));
        }

        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1,
        // 0));
        vector<vector<int>> dp(text1.size() + 1,
                               vector<int>(text2.size() + 1, 0));
        // return solve(0,0, text1, text2, dp);

        for (int i = text1.length()-1; i >= 0; i--) {
            for (int j = text2.length()-1; j >= 0; j--) {
                int ans = 0;
                if (text1[i] == text2[j]) {
                    ans = 1 + dp[i + 1][j + 1];
                } else {
                    ans = max(dp[i + 1][j], dp[i][j + 1]);
                }
dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};