class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        map<int, vector<int>>mp;
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }
        for(auto &it: mp){
            if(it.first<0){
                sort(it.second.begin(), it.second.end());
            }
            else{
                sort(it.second.rbegin(), it.second.rend());
            }
        }
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                grid[i][j] = mp[i-j].front();
                mp[i-j].erase(mp[i-j].begin());
            }
        }
        return grid;
    }
};