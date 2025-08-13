class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1); // 1-based indexing
        for (auto &it : times) {
            int u = it[0];
            int v = it[1]; 
            int w = it[2]; 
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> dist(n + 1, 1e9);

        q.push({0, k});
        dist[k] = 0;

        while (!q.empty()) {
            auto [time, node] = q.top();
            q.pop();

            if (time > dist[node]) continue;

            for (auto &[adjNode, wt] : adj[node]) {
                if (time + wt < dist[adjNode]) {
                    dist[adjNode] = time + wt;
                    q.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxdist = 0;
        for (int i = 1; i <= n; i++) { // start from 1
            if (dist[i] == 1e9) return -1;
            maxdist = max(maxdist, dist[i]);
        }
        return maxdist;
    }
};
