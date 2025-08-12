class Solution {
public:
    int MOD = 1e9+7;

    long long intPower(int base, int exp) {
        long long result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
            if (result > INT_MAX) return LLONG_MAX; // prevent overflow
        }
        return result;
    }

    int solve(int n, int x, int num, vector<vector<int>> &dp) {
        if (n == 0) return 1;
        if (n < 0) return 0;
        if (num > n) return 0; // bound check
        if (dp[n][num] != -1) return dp[n][num];

        long long numpowval = intPower(num, x);
        if (numpowval > n) return 0;

        int take = solve(n - (int)numpowval, x, num + 1, dp);
        int not_take = solve(n, x, num + 1, dp);

        return dp[n][num] = (take + not_take) % MOD;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(n, x, 1, dp);
    }
};
