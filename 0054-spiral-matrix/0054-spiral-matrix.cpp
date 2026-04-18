class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int total = n*m;
        int cnt = 0;
        int s_r = 0, s_c = 0;
        int e_r = n-1, e_c = m-1;
        vector<int> ans;
        while(cnt<total){
        for(int i = s_r; i<=e_c && cnt<total; i++){
            ans.push_back(matrix[s_r][i]);
            cnt++;
        }
        s_r++;
        for(int i = s_r; i<=e_r && cnt<total; i++){
            ans.push_back(matrix[i][e_c]);
            cnt++;
        }
        e_c--;
        for(int i = e_c; i>=s_c && cnt<total; i--){
            ans.push_back(matrix[e_r][i]);
            cnt++;
        }
        e_r--;
        for(int i = e_r; i>=s_r && cnt<total; i--){
            ans.push_back(matrix[i][s_c]);
            cnt++;

        }
        s_c++;
    }
    return ans;
    }
};