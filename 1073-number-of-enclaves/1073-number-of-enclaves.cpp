class Solution {
public:

int n , m;

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &board, int delrow[], int delcol[]){
    vis[row][col] = 1;
   // check for top, right, bottom, left
    for(int i = 0; i<4; i++){
        int nrow = row+delrow[i];
        int ncol = col+delcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol] == 1){
            dfs(nrow, ncol, vis, board, delrow, delcol);
        }
    }
}

    int numEnclaves(vector<vector<int>>& board) {
         n = board.size();
        m = board[0].size();
        int delrow[] = {-1,0, +1, 0};
        int delcol[] = {0,+1,0,-1};

        vector<vector<int>> vis(n, vector<int>(m,0));

        // traverse first row and last row
        for(int j = 0; j<m; j++){
            //first row
            if(!vis[0][j] && board[0][j] == 1){
                dfs(0,j, vis, board, delrow, delcol);
            }

            // last row
            if(!vis[n-1][j] && board[n-1][j] == 1){
                dfs(n-1,j, vis, board, delrow, delcol);
            }

        }

        //first col && last col
        for(int i = 0; i<n; i++){
            if(!vis[i][0] && board[i][0] == 1){
                dfs(i, 0, vis, board, delrow, delcol);

            }
            if(!vis[i][m-1] && board[i][m-1] == 1){
                dfs(i, m-1, vis, board, delrow, delcol);
            }
        }
        int cnt =0;
         for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && board[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};