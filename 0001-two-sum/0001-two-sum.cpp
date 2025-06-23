class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]] = i;
        }
        for(int i = 0; i<nums.size(); i++){
            int rem= target-nums[i];// rem = complement
            if(mp.count(rem) && mp[rem] != i) return {i, mp[rem]};
        }
        return {};
    }
};