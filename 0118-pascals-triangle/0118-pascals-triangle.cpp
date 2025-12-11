class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> prev;
        int ind = 0;
        vector<vector<int>> ans;
        while(ind<numRows){
            vector<int> curr(ind+1, 1);
            for(int i = 1; i<ind; i++){
                curr[i] = prev[i]+prev[i-1];
            }
            
            ans.push_back(curr);
            prev = curr;
            
            ind++;
        }
        return ans;
    }
};