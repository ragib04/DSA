class Solution {
public:
bool dfscheckcycle(int node, vector<bool> &vis, vector<bool>&pathvis, vector<int> &check, vector<vector<int>> &graph){
    vis[node] = 1;
    pathvis[node] = 1;
    for(auto neighbour: graph[node]){
        if(!vis[neighbour]){
            if(dfscheckcycle(neighbour, vis, pathvis, check, graph) == true) return true;
        }
        else if(pathvis[neighbour]) return true;
    }
    check[node] = 1;
    pathvis[node] = 0;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, 0);
        vector<bool> pathvis(n, 0);vector<int> check(n, 0);
        vector<int> safenode;
        for(int i = 0; i<n ; i++){
            if(!vis[i]){
                dfscheckcycle(i, vis, pathvis, check, graph);
            }
        }
        for(int i = 0; i<n; i++){
            if(check[i] == 1) safenode.push_back(i);
        }
        return safenode;
    }
};