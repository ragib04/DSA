class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>> adj(n+1);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int> dist(n+1, 1e9);
        vector<int> parent(n+1, -1);
       
        
        dist[1] = 0;
        pq.push({0, 1});
        while (!pq.empty()) {
    auto it = pq.top();
    int node = it.second;
    int d = it.first;
    pq.pop();

    // Skip if this is an outdated distance
    if (d > dist[node]) continue;

    for (auto &nbr : adj[node]) {
        int adjNode = nbr.first;
        int ed = nbr.second;
        if (d + ed < dist[adjNode]) {
            dist[adjNode] = d + ed;
            pq.push({dist[adjNode], adjNode});
            parent[adjNode] = node;
        }
    }
}
      if (dist[n] == 1e9) return {-1};

vector<int> path;
int node = n;
while (parent[node] != -1) {
    path.push_back(node);
    node = parent[node];
}
path.push_back(1);
reverse(path.begin(), path.end());

// Insert shortest distance at front
path.insert(path.begin(), dist[n]);

return path;
    }
};