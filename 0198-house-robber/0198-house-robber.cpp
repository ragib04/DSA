class Solution {
public:
/*.  REcursive

int hrob(int ind, vector<int> &nums){
    if(ind == 0) return nums[ind];
    if(ind<0) return 0;

    int pick = nums[ind] + hrob(ind+2, nums);
    int notpick = 0 + hrob(ind+1, nums);

    return max(pick, notpick)
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        return hrob(n-1, nums);
    }*/

    // Tabulation

    int func(int ind, vector<int> &nums, vector<int> &dp){
        if(ind<0) return 0;
        if(ind == 0) return nums[ind];
        if(dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + func(ind-2, nums, dp);
        int notpick = 0+ func(ind-1, nums, dp);

        return dp[ind] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return func(n-1, nums, dp);
    }
};