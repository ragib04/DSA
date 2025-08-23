class Disjointset {
    public:
        vector<int> parent, rank;

        Disjointset(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int findparent(int node) {
            if (parent[node] == node) return node;
            return parent[node] = findparent(parent[node]);
        }

        void unionset(int u, int v) {
            u = findparent(u);
            v = findparent(v);

            if (u == v) return;

            if (rank[u] < rank[v]) {
                parent[u] = v;
            }
            else if (rank[u] > rank[v]) {
                parent[v] = u;
            }
            else {
                parent[v] = u;
                rank[u]++;
            }
        }
    };

class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adjls) {
        vis[node] = 1;
        for (auto it : adjls[node]) {
            if (!vis[it]) {
                dfs(it, vis, adjls);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
     
        
            Disjointset ds(n);
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(isConnected[i][j] == 1) ds.unionset(i, j);
                }
            }
       
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if(ds.parent[i] == i) cnt++;
            
        }

        return cnt;
    }
};
