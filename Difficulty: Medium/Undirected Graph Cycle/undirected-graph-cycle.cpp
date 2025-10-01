class Solution {
  public:
  
  bool detectCycle(int src, int vis[], vector<vector<int>> &adj){
      vis[src] = 1;
      queue<pair<int, int>> q;
      q.push({src, -1});
      while(!q.empty()){
          int node = q.front().first;
          int parent = q.front().second;
          q.pop();
          for(auto adjnode: adj[node]){
              if(!vis[adjnode]){
                  vis[adjnode] = 1;
                  q.push({adjnode, node});
              }
              else{
                  if(parent != adjnode) return true;
              }
          }
      }
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto &edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int vis[V] = {0};
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(detectCycle(i, vis, adj)) return true;
            }
        }
        return false;
    }
};