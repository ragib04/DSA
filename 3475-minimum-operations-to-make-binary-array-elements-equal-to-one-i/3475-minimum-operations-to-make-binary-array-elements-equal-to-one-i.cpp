class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i <= n - 3; i++) {

            if (nums[i] == 0) {

                nums[i] = 1;
                nums[i + 1] = nums[i+1] == 0?1:0;
                nums[i + 2] = nums[i+2] == 0?1:0;
                cnt++;
            }
        }
        return (nums[n-2] == 1 && nums[n-1] == 1)? cnt : -1;
    }
};