class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        //finding coordinates
        int top = n;
        int bottom = -1;
        int left = m, right = -1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    top = min(top, i);
                    bottom = max(bottom, i);
                    left = min(left, j);
                    right = max(right, j);


                }
            }
        }
        return (abs(top-bottom) + 1)*(abs(left-right )+ 1);
    }
};