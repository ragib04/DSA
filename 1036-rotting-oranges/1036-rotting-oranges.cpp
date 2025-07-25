class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
       // vector<vector<int>> vis;
        int vis[n][m];
        int cntfresh = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;

                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1) cntfresh++;
            }
        }
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,1,0,-1};
        int time= 0;
        int cnt = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            
            for(int i =0; i<4; i++){
                int nrow = r+drow[i];
                int ncol= c + dcol[i];

                if(nrow>=0 && nrow<n && ncol >= 0 && ncol<m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, t+1});

                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
// to check ans fresh orange is remaining?
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<m; j++){
        //         if(vis[i][j] ! = 2 && grid[i][j] == 1) return -1;
        //     }
        // }
        if(cnt != cntfresh) return -1;
        return time;
    }
};