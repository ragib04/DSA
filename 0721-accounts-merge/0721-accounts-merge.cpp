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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjointset ds(n);
        unordered_map<string, int> mapMailNode;

        for(int i = 0; i<n; i++){
            for(int j = 1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }
                else{
                    ds.unionset(i, mapMailNode[mail]);
                }
            }
        }
        vector<vector<string>> mergedMail(n);
        for(auto it: mapMailNode){
            string mail = it.first;
            int node = ds.findparent(it.second);
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i = 0; i<n; i++){
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};