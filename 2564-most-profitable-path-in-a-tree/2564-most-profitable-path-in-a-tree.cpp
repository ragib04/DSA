class Solution {
public:
unordered_map<int, vector<int>>adj; //adjlist
unordered_map<int, int> bobMap;
int aliceIncome;
bool DFSbob(int bob, int t, vector<bool> &visited){
    visited[bob] = true;
    bobMap[bob] = t;

    if(bob == 0) return true;

    for(auto &ngbr: adj[bob]){
        if(!visited[ngbr]){
            if(DFSbob(ngbr, t+1, visited) == true) return true;
        }
    }
    bobMap.erase(bob);
    return false;
}

void DFSAlice(int curr, int t, int income, vector<bool> &visited, vector<int> &amount){
    visited[curr] = true;
    if(bobMap.find(curr) == bobMap.end() || t < bobMap[curr]){
        income += amount[curr];
    }
    else if(t == bobMap[curr]){
        income += (amount[curr]/2);
    }

    if(curr != 0 && adj[curr].size() == 1){
        aliceIncome = max(aliceIncome, income);
    }

    for(int &ngbr: adj[curr]){
        if(!visited[ngbr]){
            DFSAlice(ngbr, t+1, income, visited, amount);
        }
    }
}

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        aliceIncome = INT_MIN;
        for(vector<int> &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        int time = 0;
        vector<bool> visited(n,false);
        DFSbob(bob, time, visited);

        int income = 0;
        visited.assign(n, false);
        DFSAlice(0, 0, income, visited, amount);
        return aliceIncome;
        
    }
};