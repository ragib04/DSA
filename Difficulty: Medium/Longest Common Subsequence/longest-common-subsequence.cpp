class Solution {
  public:
    int lcs(string &text1, string &text2) {
        // code here
        vector<int> curr(text2.length() + 1, 0), next(text2.length() + 1, 0);
        for (int i = text1.length()-1; i >= 0; i--) {
            for (int j = text2.length()-1; j >= 0; j--) {
                int ans = 0;
                if (text1[i] == text2[j]) {
                    ans = 1 + next[j + 1];
                } else {
                    ans = max(next[j], curr[j + 1]);
                }
curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
};
