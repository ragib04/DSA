class Solution {
  public:
  
  void topodfs(int node, vector<bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj){
      vis[node] = 1;
      for(auto neigh: adj[node]){
          if(!vis[neigh]){
              topodfs(neigh, vis, st, adj);
          }
          
      }
      st.push(node);
  }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, list<int>>adj;
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<bool> vis(V, false);
        stack<int> st;
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                topodfs(i, vis,st, adj);
            }
            
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};