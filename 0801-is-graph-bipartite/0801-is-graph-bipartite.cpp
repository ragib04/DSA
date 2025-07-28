class Solution {
public:

bool solve(int start, vector<int> &vis, vector<vector<int>> &graph){
    queue<int> q;
    vis[start] = 0;
    q.push(start);

    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto it: graph[front]){
            if(vis[it] == -1){
                vis[it] = !vis[front];
                q.push(it);
            }
            else if(vis[it] == vis[front]) return false;
        }
    }
    return true;

}
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colorvis(n, -1);
        for(int i = 0; i<n; i++){
            if(colorvis[i] == -1){
                if(solve(i, colorvis, graph )== false) return false;
            }
        }
        return true;
    }
};