class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
       vector<vector<pair<int, int>>> adj(V);
        for(auto &i: edges){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int wt = it.first;
            pq.pop();
            
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum += wt;
            for(auto it: adj[node]){
                int adjnode = it.first;
                int w = it.second;
                if(vis[adjnode] == 0){
                    pq.push({w,adjnode});
                }
            }
        }
        return sum;
    }
};