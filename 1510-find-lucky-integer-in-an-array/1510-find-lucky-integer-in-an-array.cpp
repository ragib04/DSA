class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto it: arr){
            mp[it]++;
        }
        int maxi = -1;
        for(auto i: mp){
            if(i.second == i.first){
                maxi = max(maxi, i.first);
            }
        }
        return maxi;

    }
};