/*
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

};*/

/*

// Tabulation->>>>>>>>>>>
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        dp[0][0] = 1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1) dp[i][j] = 0;
                else if(i == 0 && j ==0) dp[0][0] = 1;
                else{
                   int left = 0, up = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];

                    dp[i][j] = left+up;
                }

            }
        }
        return dp[n-1][m-1];
    }
};*/

class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<int> prev(n, 0);

        for(int i = 0; i < m; i++){

            vector<int> temp(n, 0);

            for(int j = 0; j < n; j++){

                if(obstacleGrid[i][j] == 1){
                    temp[j] = 0;
                    continue;
                }

                if(i == 0 && j == 0){
                    temp[j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;
   
                if(i > 0)
                    up = prev[j];
                    
                if(j > 0)
                    left = temp[j - 1];

                temp[j] = up + left;
            }

            prev = temp;
        }

        return prev[n - 1];
    }
};
