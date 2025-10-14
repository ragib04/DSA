class Solution {
public:

bool dfs(int node, bool col, vector<int>& color, vector<vector<int>> &graph){
    color[node] = col;
    for(auto it: graph[node]){
        if(color[it] == -1){
            if(dfs(it, !col, color, graph) == false) return false;
        }
        else if(color[it] == col) return false;
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i<n; i++){
            if(color[i] == -1){
                if(dfs(i, 0, color, graph) == false) return false;
            }
        }
        return true;
        
    }
};



/*
class Solution {
public:
bool bfs(int i, vector<int>&col, vector<vector<int>>&graph){
    col[i] = 0;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto it: graph[front]){
            if(col[it] == -1){
                col[it] = 1-col[front];
                q.push(it);
            }
            else{
                if(col[it] == col[front]) return false;
            }
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>col(n, -1);
        for(int i = 0; i<n; i++){
            if(col[i] == -1){
                if(bfs(i, col, graph) == false) return false;
            }
        }
        return true;
    }
};
*/