class Solution {
public:
    int solve(int i, string& s, int& n, vector<int>& dp) {
        if (i == n)
            return 1;
        if (s[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int pick = solve(i + 1, s, n, dp);

        if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            pick += solve(i + 2, s, n, dp);
        }

        return dp[i] = pick;
    }
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        // vector<int> dp(n+1, -1);
        // return solve(0, s, n, dp);

        // vector<int> dp(n + 1, 0);
        // dp[n] = 1;
        // for (int i = n - 1; i >= 0; i--) {
        //     if (s[i] == '0') {
        //         dp[i] = 0;
        //     } else {
        //         int pick = dp[i + 1];
        //         if (i + 1 < n &&
        //             (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
        //             pick += dp[i + 2];

        //         dp[i] = pick;
        //     }
        // }
        // return dp[0];




         int next = 1;      // dp[i+1]
        int nextNext = 0;  // dp[i+2]
        int curr = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                curr = 0;  // can't decode starting with '0'
            } else {
                curr = next;  // single character decode

                if (i + 1 < n) {
                    int twoDigit = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    if (twoDigit >= 10 && twoDigit <= 26)
                        curr += (i + 2 <= n ? nextNext : 1);
                }
            }

            nextNext = next;
            next = curr;
        }

        return curr;
    
    }
};