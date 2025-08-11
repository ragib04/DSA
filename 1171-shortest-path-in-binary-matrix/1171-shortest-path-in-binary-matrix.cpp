class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if (n == 1 && grid[0][0] == 0) return 1;
        
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(n,1e9));
        dist[0][0] = 1;
        q.push({1, {0,0}});
        int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i = 0; i<8; i++){
                int newr = dr[i]+r;
                int newc = dc[i]+ c;

                if(newr>=0 && newr <n && newc >= 0 && newc < n && grid[newr][newc] == 0 && d+1 < dist[newr][newc]){
                    dist[newr][newc] = d+1;
                    if(newr == n-1 && newc == n-1) return d+1;

                    q.push({1+d, {newr, newc}});
                }
            }
        }
        return -1;

    }
};