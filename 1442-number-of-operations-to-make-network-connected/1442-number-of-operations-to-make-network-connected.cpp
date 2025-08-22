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
   

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1; // not enough edges

        Disjointset ds(n);
        int cntextraedges = 0;

        for (auto &it : connections) {
            int u = it[0];
            int v = it[1];

            if (ds.findparent(u) == ds.findparent(v)) {
                cntextraedges++;
            } else {
                ds.unionset(u, v);
            }
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) components++;
        }

        int required = components - 1;
        if (cntextraedges >= required) return required;
        else return -1;
    }
};
