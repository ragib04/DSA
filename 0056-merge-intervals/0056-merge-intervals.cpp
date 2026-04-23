class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervels) {
        sort(intervels.begin(), intervels.end());
        vector<vector<int>> ans;
        int s = intervels[0][0], e = intervels[0][1];
        for(int i = 1; i<intervels.size(); i++){
            if(intervels[i][0]<=e){
                if(e<intervels[i][1])
                    e = intervels[i][1];

            }
            else{
                ans.push_back({s,e});
                s = intervels[i][0];
                e = intervels[i][1];
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};