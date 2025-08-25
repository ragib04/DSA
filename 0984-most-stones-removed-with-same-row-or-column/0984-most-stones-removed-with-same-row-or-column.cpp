class Solution {
public:

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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxrow = 0;
        int maxcol = 0;
        for(auto it: stones){
            maxrow = max(maxrow, it[0]);
            maxcol = max(maxcol, it[1]);
        }
        Disjointset ds(maxrow+maxcol+2);
        unordered_map<int, int> stoneNodes;
        for(auto it: stones){
            int noderow = it[0];
            int nodecol = it[1]+maxrow+1;
            ds.unionset(noderow, nodecol);
            stoneNodes[noderow] = 1;
            stoneNodes[nodecol] = 1;

        }
        int cnt = 0;
        for(auto it: stoneNodes){
            if(ds.findparent(it.first) == it.first) cnt++;
        }
        return n - cnt;
    }
};