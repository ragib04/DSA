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