class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto it: adj[front]){
                if(dist[front]+1 < dist[it]){
                    dist[it] = dist[front]+1;
                    q.push(it);
                }
            }
        }
        vector<int> ans(n, -1);
        for(int i = 0; i<n; i++){
            if(dist[i] != 1e9) ans[i] = dist[i];
        }
        return ans;
    }
};