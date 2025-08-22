class Solution {
public:
// int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
    
//     int n = matrix.size(), m = matrix[0].size();
//     if(i>=n || j>= m) return 0;
//     if(dp[i][j] != -1) return dp[i][j];
//     int left = solve(matrix, i, j+1, dp);
//     int diagonal = solve(matrix, i+1, j+1, dp);
//     int down = solve(matrix, i+1, j, dp);

//     if(matrix[i][j] == 1){
//         dp[i][j] = 1+min(left, min(diagonal, down));
//         return dp[i][j];
//     }
//     else return dp[i][j] = 0;

    
// }
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        //solve(matrix, 0,0, dp);
        //Tabu
        //basee case
        for(int i = 0; i<matrix.size(); i++) dp[i][0] = matrix[i][0];
        for(int j = 0; j<matrix[0].size(); j++) dp[0][j] = matrix[0][j];

        for(int i = 1; i<matrix.size(); i++){
            for(int j = 1; j<matrix[0].size(); j++){
                
                if(matrix[i][j] == 1) dp[i][j] = 1+ min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
            }
        }
        int sum = 0;
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                sum += dp[i][j];
            }
        }
return sum;
    }
};