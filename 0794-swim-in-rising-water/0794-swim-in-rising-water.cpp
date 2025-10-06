class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!pq.empty()){
            auto [t, p] = pq.top();
            pq.pop();
            int r = p.first, c = p.second;

            if (vis[r][c]) continue;
            vis[r][c] = 1;

            if(r == n-1 && c == m-1)
                return t;

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int newTime = max(t, grid[nr][nc]);
                    if(newTime < dist[nr][nc]){
                        dist[nr][nc] = newTime;
                        pq.push({newTime, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};
