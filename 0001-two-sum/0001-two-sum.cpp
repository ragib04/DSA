class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //brute force
        // for(int i = 0; i<nums.size(); i++){
        //     for(int j = i+1; j<nums.size();j++){
        //         if(nums[j] == target-nums[i]){
        //             return {i, j};
        //         }
        //     }
        // }
        // return {};
        unordered_map<int, int> mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]] = i;

        }
        for(int i = 0; i<nums.size(); i++){
            int remaning = target- nums[i];
            if(mp.find(remaning) != mp.end() && i != mp[remaning]){
                
                return {i, mp[remaning]};
            }
        }
        return {};
    }
};