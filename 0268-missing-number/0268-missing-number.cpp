class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        int ans;
        for(int i = 0; i<=nums.size(); i++){
            if(mp.find(i) == mp.end()){
                ans = i;
                break;
            }
        }
        return ans;
    }
};