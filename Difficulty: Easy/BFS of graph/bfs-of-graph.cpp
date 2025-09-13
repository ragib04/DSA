class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    void BFST(int node, vector<vector<int>> &adj, vector<int> &ans, vector<bool> &vis, int n){
       queue<int> q;
        vis[node] = 1;
        q.push(node);
        while(!q.empty()){
            int frontnode = q.front();
            q.pop();
            ans.push_back(frontnode);
            for(auto it: adj[frontnode]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
            
        }
            
        
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n = adj.size();
        vector<int> ans;
        vector<bool> vis(n, 0);
        
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                BFST(i, adj, ans, vis, n);
            }
        }
        return ans;
        
    }
};