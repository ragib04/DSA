class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i = 0; i<nums.size(); i++){
            if(mpp.find(nums[i]) != mpp.end()) return true;

            mpp[nums[i]] = 1;

        }
        return false;
    }
};