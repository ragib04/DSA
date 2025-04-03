class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res = 0;
        int max_diff = 0, max_num = 0;

        for (int i = 0; i < nums.size(); i++) {
            res = max(res, (long long) max_diff * nums[i]);
            max_diff = max(max_diff, max_num - nums[i]);
            max_num = max(max_num, nums[i]);
        }
        return res;
    }
};