class Solution {
  public:
    vector<int> topoSort(int v, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, list<int>> adj;
        for(int i= 0; i<edges.size(); i++){
            int x = edges[i][0];
            int y = edges[i][1];
            adj[x].push_back(y);
        }
        // find all indegree
        vector<int> indegree(v);
        for(auto i: adj){
            for(auto j: i.second){
                indegree[j]++;
            }
        }
        queue<int> q;
        //push all 0 indegree in the queue
        for(int i = 0; i<v; i++){
            if(indegree[i] == 0) q.push(i);
        }
        // do bfs
        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            ans.push_back(front);
            //neighbour indegree update
            for(auto node: adj[front]){
                indegree[node]--;
                if(indegree[node] == 0) q.push(node);
            }
        }
        return ans;
    }
};