class Solution {
  public:
  
      bool dfs(vector<vector<int>>& adj, vector<bool> &visited, unordered_set<int>& currentpath, int vertex) {
        vector<int>sides = adj[vertex];
        
        for(int i=0;i<sides.size();i++) {
            if(!visited[sides[i]]) {
                currentpath.insert(sides[i]);
                visited[sides[i]]=true;
                bool x = dfs(adj,visited,currentpath,sides[i]);
                if(x) {
                    return true;
                }
            } else {
                if(currentpath.find(sides[i])!=currentpath.end()) {
                    return true;
                }
            }
        }
        currentpath.erase(vertex);
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj = vector<vector<int>>(V);
        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        for(int i=0;i<V;i++) {
        vector<bool>visited = vector<bool>(V,false);
        unordered_set<int>path;
        path.insert(i);
        visited[i]=true;
            if(dfs(adj,visited,path,i)) {
                return true;
            }
        }
        return false;
    
    }
};