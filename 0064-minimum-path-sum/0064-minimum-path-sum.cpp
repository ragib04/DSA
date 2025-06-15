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