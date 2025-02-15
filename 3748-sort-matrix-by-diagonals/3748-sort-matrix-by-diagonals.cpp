class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int, vector<int>> mpp;
        int r = grid.size(), c = grid[0].size();

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                mpp[i-j].push_back(grid[i][j]);
            }
        }
        for(auto &entry : mpp){
            if(entry.first<0) sort(entry.second.begin(), entry.second.end());
            else sort(entry.second.rbegin(),entry.second.rend());
        }

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                grid[i][j] = mpp[i-j].front();
                mpp[i-j].erase(mpp[i-j].begin());
            }
        }
        return grid;
    }
};