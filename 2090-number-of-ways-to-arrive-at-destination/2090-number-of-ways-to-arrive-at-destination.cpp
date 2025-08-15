class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it: roads){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        int mod = (int)(1e9+7);
        while(!pq.empty()){
            long long node= pq.top().second;
            long long d = pq.top().first;
            pq.pop();
            if (d > dist[node]) continue;
            for(auto i: adj[node]){
                int adjNode = i.first;
                int wt = i.second;
                if(wt+d < dist[adjNode]){
                    dist[adjNode] = wt+d;
                    ways[adjNode] = ways[node];
                    pq.push({wt+d, adjNode});
                }
                else if(wt+d == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};