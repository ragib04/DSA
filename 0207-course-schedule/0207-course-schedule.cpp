class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& edges) {
         vector<vector<int>> adj(v);
        for(int i= 0; i<edges.size(); i++){
            int x = edges[i][0];
            int y = edges[i][1];
            adj[x].push_back(y);
        }
        // find all indegree
        vector<int> indegree(v);
        for(int i = 0; i<v; i++){
            for(auto j: adj[i]){
                indegree[j]++;
            }
        }
        queue<int> q;
        //push all 0 indegree in the queue
        for(int i = 0; i<v; i++){
            if(indegree[i] == 0) q.push(i);
        }
        // do bfs
        int cnt = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            cnt++;
            //neighbour indegree update
            for(auto node: adj[front]){
                indegree[node]--;
                if(indegree[node] == 0) q.push(node);
            }
        }
        if(cnt == v) return true;
        return false;
            
    }
};