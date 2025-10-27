class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto it: times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n+1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();
            if(time > dist[node]) continue;
            for(auto it: adj[node]){
                int adjnode = it.first;
                int wt = it.second;
                if(wt+time < dist[adjnode]){
                    dist[adjnode] = wt+time;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }
        int maxdist = 0;
        for(int i = 1; i<=n; i++){
            if(dist[i] == 1e9) return -1;
            maxdist = max(maxdist, dist[i]);
        }
        return maxdist;
    }
};