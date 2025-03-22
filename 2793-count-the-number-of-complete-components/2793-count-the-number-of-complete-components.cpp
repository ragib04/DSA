class Solution {
public:
    void bfs(int i, unordered_map<int, vector<int>>& adj, vector<bool>& visited, int& v, int &e) {
        queue<int> que;
        que.push(i);
        visited[i] = true;

        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            v++;
            e += adj[curr].size();

            for(int &ngbr : adj[curr]) {
                if(!visited[ngbr]) {
                    visited[ngbr] = true;
                    que.push(ngbr);
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        int result = 0;

        //Build the graph
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(visited[i] == true) {
                continue;
            }
            int v = 0;
            int e = 0;
            bfs(i, adj, visited, v, e);

            if((v*(v-1)) == e) {
                result++;
            }
        }
        
        return result;
    }
};