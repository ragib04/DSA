class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int ans = 0;
        vector<int> row(n,0), col(m,0);
        // row = [1, 1, 1]
        // col = [2, 0, 1]
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 1 && row[i] == 1 && col[j] == 1) ans++;
            }
        }
        return ans;
    }
};