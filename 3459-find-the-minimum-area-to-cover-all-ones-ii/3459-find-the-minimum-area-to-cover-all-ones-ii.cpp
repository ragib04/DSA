class Solution {
public:

 int minArea(int startrow, int endrow, int startcol, int endcol, vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        //finding coordinates
        int top = n;
        int bottom = -1;
        int left = m, right = -1;
        for(int i = startrow; i<endrow; i++){
            for(int j = startcol; j<endcol; j++){
                if(grid[i][j] == 1){
                    top = min(top, i);
                    bottom = max(bottom, i);
                    left = min(left, j);
                    right = max(right, j);


                }
            }
        }
         if(bottom == -1) return 0;
        return (abs(top-bottom) + 1)*(abs(left-right )+ 1);
    }

    int func(vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        int res = INT_MAX;

        for(int rs = 1; rs<m; rs++){
            for(int cs = 1; cs<n; cs++){
                int top = minArea(0, rs, 0, n, grid);
                int bottomleft = minArea(rs, m, 0, cs, grid);
                int bottomright = minArea(rs, m, cs, n, grid);

                res = min(res, top+bottomleft+bottomright);

                int topleft = minArea(0, rs, 0, cs, grid);
                int topright = minArea(0, rs, cs, n, grid);
                int bottom = minArea(rs, m, 0, n, grid);

                res = min(res, topleft+topright+bottom);
            }
        }
        for(int rs1 = 0; rs1 <m; rs1++){
            for(int rs2 = 0; rs2<m; rs2++){
                int top = minArea(0, rs1, 0, n, grid);
                int middle = minArea(rs1, rs2, 0, n, grid);
                int bottom = minArea(rs2, m, 0, n, grid);

                res = min(res, top+middle+bottom);
            }
        }
        return res;
    }

    vector<vector<int>> rotateclockWise(vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rotateGrid(n, vector<int>(m));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                rotateGrid[j][m-i-1] = grid[i][j];
            }
        }
        return rotateGrid;
    }
    int minimumSum(vector<vector<int>>& grid) {
        int res = func(grid);
        vector<vector<int>> rotatedGrid = rotateclockWise(grid);

        res = min(res, func(rotatedGrid));
        return res;
    }
};