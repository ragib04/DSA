class Solution {
public:

 bool isincreasing(int s, int e, vector<int> &nums) {
        // check strictly increasing between s and e-1
        for (int i = s+1; i < e; i++) {
            if (nums[i] <= nums[i - 1])
                return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i +2*k <= n; i++){
            bool first = isincreasing(i, i+k, nums);
            bool second = isincreasing(i+k, i+ 2*k, nums);

            if(first == true && second == true) return true;
        }
        return false;
    }
};