class Solution {
public:

int solve(int ind, vector<int> &nums, vector<int> &dp){
    if(ind == 0) return nums[ind];
    if(ind<0) return 0;
    if(dp[ind] != -1) return dp[ind];
    int pick = nums[ind]+solve(ind-2, nums, dp);
    int not_pick = solve(ind-1, nums, dp);

    dp[ind] = max(pick, not_pick);
    return dp[ind];
}
int robber(vector<int> &nums){
    int n = nums.size();
//memoization
    vector<int> dp(n+1, -1);
    return solve(n-1, nums, dp);
//Tabulation
    // vector<int> dp(n+1, 0);
    // dp[0] = nums[0];
    // for(int i = 1; i<n; i++){
    //     int pick = nums[i];
    //     if(i>1) pick += dp[i-2];
    //     int not_pick = dp[i-1];

    //     dp[i] = max(pick, not_pick);
    // }
    // return dp[n-1];
    
    //Space Optimization
//     int prev1 = nums[0], prev2 = 0;
//     for(int i = 1; i<n; i++){
//         int take = nums[i];
//         if(i>1) take += prev2;
//         int nottake = prev1;
//         int curr = max(take, nottake);
//         prev2 = prev1;
//         prev1 = curr;
//     }
// return prev1;

}
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> temp1, temp2;
        for(int i = 0; i<n; i++){
            if(i != 0) temp1.push_back(nums[i]);    //ignore the first idx
            if(i != n-1) temp2.push_back(nums[i]);  //ignore the last idx
        }
        return max(robber(temp1), robber(temp2));

    }
};