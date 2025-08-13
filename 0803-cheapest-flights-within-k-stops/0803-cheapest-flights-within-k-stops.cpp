class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<pair<int, int>> adj[n]; // n = number of nodes
        for (auto &it : flights) {
            int u = it[0];
            int v = it[1]; 
            int w = it[2]; 
            adj[u].push_back({v, w});
        }
        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);
        q.push({0, {src, 0}});
        dist[src] = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int node= it.second.first;
            int cost = it.second.second;

            if(stop > k) continue;
            for(auto i: adj[node]){
                int adjNode = i.first;
                int wt = i.second;

                if(cost+wt < dist[adjNode] && stop <= k){
                    dist[adjNode] = cost+wt;
                    q.push({stop+1, {adjNode, cost+wt}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;

        return dist[dst];
    }
};