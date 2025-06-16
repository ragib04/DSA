/*class Solution {
public:

int solve(int i, int j, vector<vector<int>> &matrix, int m, vector<vector<int>> & dp){
    if(j<0 || j>=m) return INT_MAX;

    if(i == 0) return matrix[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int ld =  solve(i-1, j-1, matrix, m, dp) ;
    int up = solve(i-1, j, matrix, m, dp);
    int rd =  solve(i-1, j+1, matrix, m, dp);

    return dp[i][j] = matrix[i][j] + min(up, min(ld, rd));

}


    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        int mini = INT_MAX;
        for(int j = 0; j<m; j++){
             int ans = solve(n-1, j, matrix, m, dp);
             mini = min(mini, ans);
        }
        return mini;
    }
};

*/


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

/*
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> front(m), curr(m);

        for(int j = 0; j<m; j++){
            front[j] = matrix[0][j];
        }
        for(int i = 1; i<n; i++){
            for(int j=0; j<m; j++){
                int ld = (j>0)? front[j-1]: INT_MAX;
                int up = front[j];
                int rd = (j<m-1) ? front[j+1]: INT_MAX;

                curr[j] = matrix[i][j] + min(ld, min(up, rd));
            }
            front = curr;
        }
        int mini = INT_MAX;
        for(int j = 0; j<m ;j++){
            mini = min(mini, front[j]);
        }
        return mini;
    }
};*/