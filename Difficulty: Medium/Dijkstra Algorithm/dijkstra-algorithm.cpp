class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); 
        }

        set<pair<int, int>> st;
        
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        st.insert({0, src});

        while(!st.empty()){
            auto it = *(st.begin());
            int node= it.second;
            int d = it.first;
            st.erase(it);
            for(auto it: adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if (d + wt < dist[adjNode]) {
    if (dist[adjNode] != 1e9) {
        st.erase({dist[adjNode], adjNode});
    }
    dist[adjNode] = d + wt;
    st.insert({dist[adjNode], adjNode});
}
                
            }
        }

        return dist;
    }
};
