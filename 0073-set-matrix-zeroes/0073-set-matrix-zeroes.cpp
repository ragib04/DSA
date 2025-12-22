class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        stack<pair<int, int>> st;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 0) st.push({i, j});
            }
        }

        while(!st.empty()){
            int row = st.top().first;
            int col = st.top().second;
            st.pop();
            for(int j = 0; j<m; j++){
                if(matrix[row][j] != 0) matrix[row][j] = 0;
            }
            for(int i = 0; i<n; i++){
                if(matrix[i][col] != 0) matrix[i][col] = 0;
            }

        }

    }
};