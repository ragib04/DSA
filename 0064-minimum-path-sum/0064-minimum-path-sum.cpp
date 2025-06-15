class Solution {
public:

// int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
//     if(i == 0 && j == 0) return grid[i][j];
//     if(i<0 || j<0) return INT_MAX;

//     if(dp[i][j] != -1) return dp[i][j];

//     int up = solve(i-1, j, grid, dp);
//     int left = solve(i, j-1, grid, dp);

//     return dp[i][j] = grid[i][j]+ min(left, up);
// }
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
       // return solve(n-1, m-1, grid, dp);
       for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(i == 0 && j== 0) dp[i][j] = grid[i][j];
            else{
                int up = INT_MAX, left = INT_MAX;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];

                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
       }
       return dp[n-1][m-1];
    }
};