class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        int maxi = 0;

        for(auto i:mp){
            if(i.second>= maxi){
                maxi = i.second;
            }
        }
        int cnt = 0;
        for(auto it: mp){
            if(it.second == maxi){
                cnt+=maxi;
            }
        }
        return cnt;
    }
};