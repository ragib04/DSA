class Solution {
public:
//memoization
int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp){
   // memoization solution


        if(i >= 0 && j >= 0 && grid[i][j] == 1) return 0;
       
        if(i == 0 && j == 0) return 1;
     
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j]; 

        int up = solve(grid, i-1, j, dp);
        int left = solve(grid, i, j-1, dp);

        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(); // rows
        int m = grid[0].size(); // cols
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(grid, n-1, m-1, dp);
    }

};