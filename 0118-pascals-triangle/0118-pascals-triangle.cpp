class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int ind = 0;
        vector<int> prev;
        vector<vector<int>> ans;
        while(ind<numRows){
            vector<int> curr(ind+1, 1);
            for(int i = 1; i<ind; i++){
                curr[i] = prev[i]+prev[i-1];
            }
            prev = curr;
            ans.push_back(curr);
            ind++;
        }
        return ans;
    }
};