class Solution {
public:
int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
    
    int n = matrix.size(), m = matrix[0].size();
    if(i>=n || j>= m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int left = solve(matrix, i, j+1, dp);
    int diagonal = solve(matrix, i+1, j+1, dp);
    int down = solve(matrix, i+1, j, dp);

    if(matrix[i][j] == 1){
        dp[i][j] = 1+min(left, min(diagonal, down));
        return dp[i][j];
    }
    else return dp[i][j] = 0;

    
}
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        solve(matrix, 0,0, dp);
        int sum = 0;
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                sum += dp[i][j];
            }
        }
return sum;
    }
};