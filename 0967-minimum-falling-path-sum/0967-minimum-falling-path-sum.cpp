/*
class Solution {
public:

int f(int i, int j,int m, vector<vector<int> > &matrix, vector<vector<int>> &dp){
    
    if(j<0 || j>=m) return INT_MAX;
    if(i == 0) return matrix[0][j];
    if(dp[i][j] != -1) return dp[i][j];
    int up = matrix[i][j] + f(i-1, j, m, matrix, dp);
    int leftdiag = (j>0)? matrix[i][j] + f(i-1, j-1, m, matrix, dp) : INT_MAX;
    int rightdiag =(j<m-1)?  matrix[i][j] + f(i-1, j+1, m, matrix, dp): INT_MAX;

    return dp[i][j] = min(up, min(leftdiag, rightdiag));
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n = matrix.size();
      int  m = matrix[0].size();
       vector<vector<int>> dp(n, vector<int>(m, -1));
        int mini = INT_MAX; 

    for (int j = 0; j < m; j++) {
        int ans = f(n - 1, j, m, matrix, dp); 
        mini = min(mini, ans); 
    }
    return mini;
    }
};*/

//Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++) {
        dp[0][j] = matrix[0][j];
    }
    
    for(int i = 1; i<n; i++){
        for(int j =0; j<m; j++){
            int ld = (j>0)? dp[i-1][j-1]: INT_MAX;
            int up = dp[i-1][j];
            int rd = (j < m-1)? dp[i-1][j+1]: INT_MAX;

            dp[i][j] = matrix[i][j] + min(ld, min(up, rd));
        }
    }
    int ans  = INT_MAX;
    for(int j = 0; j<m; j++){
        ans = min(ans, dp[n-1][j]);
    }
    return ans;

    
    }
};
