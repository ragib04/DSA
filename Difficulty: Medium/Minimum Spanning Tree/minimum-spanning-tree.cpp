class Solution {
public:
 static bool comp(const vector<int> &a, const vector<int> &b) {
        return a[2] < b[2];
    }
int findparent(vector<int> &parent, int node) {
        if (parent[node] == node) return node;
        return parent[node] = findparent(parent, parent[node]);
    }


    void unionset(int u, int v, vector<int> &parent, vector<int> &rank) {
        u = findparent(parent, u);
        v = findparent(parent, v);

        if (u == v) return;

        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[v] < rank[u]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }

    int spanningTree(int V, vector<vector<int>> &edges) {
    
        sort(edges.begin(), edges.end(), comp);
vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; i++) parent[i] = i;

        int minwt = 0;
        for (int i = 0; i < edges.size(); i++) {
            int u = findparent(parent, edges[i][0]);
            int v = findparent(parent, edges[i][1]);
            int wt = edges[i][2];

            if (u != v) {
                minwt += wt;
                unionset(u, v, parent, rank);
            }
        }
        return minwt;
    }
};
