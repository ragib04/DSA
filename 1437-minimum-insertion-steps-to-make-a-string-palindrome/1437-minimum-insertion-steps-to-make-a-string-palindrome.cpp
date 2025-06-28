class Solution {
public:
int longestCommonSubsequence(string text1, string text2) {
      
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
     

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

    int minInsertions(string s) {
       int n =s.length();
       string revstr = s;
       reverse(revstr.begin(), revstr.end());
       int x = longestCommonSubsequence(s, revstr);

       return (n-x); 
    }
};