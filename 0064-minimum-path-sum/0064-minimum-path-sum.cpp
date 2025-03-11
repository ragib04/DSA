/*
class Solution {
public:

int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i ==0 && j== 0) {
        return grid[0][0];
    }
    if(i<0 || j<0) return INT_MAX;
    if(dp[i][j] != -1) return dp[i][j];
   // int left = INT_MAX, up = INT_MAX;
    
    int up = f(i-1, j, grid, dp);
     int left = f(i, j-1, grid, dp);

    return dp[i][j] = grid[i][j] + min(up,left);
}
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
      vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, grid, dp);
        
    }
};
*/
/* Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i==0 && j==0) dp[0][0] = grid[0][0];
                else{
                   int up = INT_MAX, left = INT_MAX;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];


                    dp[i][j]  = grid[i][j] + min(up, left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<int> prev(m,0);
        for(int i = 0; i<n; i++){
            vector<int> curr(m,0);
            for(int j = 0; j<m; j++){
                if(i ==0 && j==0){
                    curr[j] = grid[i][j];
                }
                else{
                    int up = INT_MAX, left = INT_MAX;
                    if(i>0) up = prev[j];

                    if(j>0) left = curr[j-1];

                    curr[j] = grid[i][j] + min(left, up);
                }
            }
            prev = curr;

        }
        return prev[m-1];
    }
};