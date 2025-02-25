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
/*
    // memoization

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
    }*/


    int rob(vector<int>& nums) {
        int n = nums.size();
        //vector<int> dp(n);
        int prev1 = nums[0];
        int prev2 = 0;
       
        for(int i = 1; i<n; i++){
            int pick = nums[i];
            if(i>1) pick += prev2;
            int notpick = 0+prev1;

            int curr = max(pick, notpick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};