class Solution {
public:
  int largestMagicSquare(vector<vector<int>>& grid) {
    int y = grid.size(), x = grid[0].size();
    vector<vector<int>> h(y+1, vector<int>(x+2,0));
    vector<vector<int>> v(y+1, vector<int>(x+2,0));
    vector<vector<int>> dl(y+1, vector<int>(x+2,0));
    vector<vector<int>> dr(y+1, vector<int>(x+2,0));

    for(int i = 0; i != y; i++)
      for(int j = 0; j != x; j++){
        h[i+1][j+1] = grid[i][j] + h[i+1][j];
        v[i+1][j+1] = grid[i][j] + v[i][j+1];
        dl[i+1][j+1] = grid[i][j] + dl[i][j];
        dr[i+1][j+1] = grid[i][j] + dr[i][j+2];
      }

    for(int m = min(x,y); m != 1; m--)
      for(int i = 0; i + m <= y; i++)
        for(int j = 0; j + m <= x; j++){
          int x = dl[i+m][j+m] - dl[i][j];
          if(x != dr[i+m][j+1] - dr[i][j+m+1]) goto mark;

          for(int r = i+1; r <= i+m; r++)
            if(x != h[r][j+m] - h[r][j]) goto mark;

          for(int c = j+1; c <= j+m; c++)
            if(x != v[i+m][c] - v[i][c]) goto mark;

          return m;
          mark:;
        }

    return 1;
  }
};