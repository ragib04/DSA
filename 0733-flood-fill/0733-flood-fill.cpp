class Solution {
public:

void dfs(int r, int c, vector<vector<int>> &ans,vector<vector<int>> &img, int color, int delrow[], int delcol[], int initial){
    ans[r][c] = color;
    int n = img.size();
    int m = img[0].size();
    for(int i= 0; i<4; i++){
        int nrow = r + delrow[i];
        int ncol = c + delcol[i];
        if(nrow>= 0  && nrow<n && ncol >= 0 && ncol <m && img[nrow][ncol] == initial && ans[nrow][ncol] != color){
            dfs(nrow, ncol, ans, img, color, delrow, delcol, initial);
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialcolor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0,+1, 0, -1};

        dfs(sr, sc, ans, image, color, delrow, delcol, initialcolor);
        return ans;
            }
};