class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<int> height(c, 0);
        int res = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                // update histogram heights
                if (mat[i][j]) height[j]++;
                else height[j] = 0;

                // expand left to count submatrices
                int mn = height[j];
                for (int k = j; k >= 0 && mn > 0; k--) {
                    mn = min(mn, height[k]);
                    res += mn;
                }
            }
        }
        return res;
    }
};