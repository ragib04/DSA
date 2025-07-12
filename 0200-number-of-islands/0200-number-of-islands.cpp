class Solution {
public:

void dfs(int i, int j, int n, int m, vector<vector<char>>& grid){
    if(grid[i][j] == '0') return;
    grid[i][j]= '0';

    if(i+1<n) dfs(i+1, j, n, m, grid);
    if(i-1>=0) dfs(i-1, j, n, m, grid);
    if(j+1<m) dfs(i, j+1, n, m, grid);
    if(j-1 >= 0) dfs(i, j-1, n, m, grid);
}
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i, j, n, m, grid);
                }
            }
        }
        return cnt;
    }
};