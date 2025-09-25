class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //brute force
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size();j++){
                if(nums[j] == target-nums[i]){
                    return {i, j};
                }
            }
        }
        return {};
        // unordered_map<int, int> numMap;
        // int n = nums.size();

        // for (int i = 0; i < n; i++) {
        //     int complement = target - nums[i];
        //     if (numMap.count(complement)) {
        //         return {numMap[complement], i};
        //     }
        //     numMap[nums[i]] = i;
        // }

        // return {}; // No solution found
   // }
    }
};