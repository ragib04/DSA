class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
    // we need a dist arr for cal the dis
    /*
    it is Ug to we can use Bfs bcz we need shortest path adn bfs trav lvl wise.
    dfs go depth and backtrack at the time backtrack it may return higher val
    dfs does not gurantee the shortest path thats why we use bfs
    in bfs traf wee need quee bcz we travel level wise and store evry not quee give fifo 
    
    
    */
    int n = adj.size();
    
    vector<int> dist(n, 1e9);
    // src node dist is always 0
    dist[src] = 0;
    //for tacking the path
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node  = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(dist[node]+1 < dist[it]){
                dist[it] = dist[node]+1;
                q.push(it);
            }
        }
    }
    
    for(int i = 0; i<n; i++){
        if(dist[i] == 1e9) dist[i] = -1;
    }
    return dist;
    
    
    }
};