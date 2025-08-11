class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        vector<long long> power;
        while(n>0){
            long long lowestBit = n & -n;
            power.push_back(lowestBit);
            n = n- lowestBit;
        }
        vector<int> ans;
        for(int i = 0; i<queries.size(); i++){
            int s = queries[i][0];
            int e = queries[i][1];
            long long multiplier = power[s];
            for(int ind = s+1; ind<=e; ind++){
                multiplier = (multiplier * power[ind])%MOD;
            }
            ans.push_back((int)multiplier);
        }
        return ans;
    }
};