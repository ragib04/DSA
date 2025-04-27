class Solution {
public:

bool subsetsum(int ind, int target, vector<int>&nums, vector<vector<int>> &dp){
    if(target == 0) return true;
    if(ind == 0) return (nums[ind] == 0);

    if(dp[ind][target] != -1) return dp[ind][target];

    bool not_take = subsetsum(ind-1, target, nums, dp);
    bool take = false;
    if(target>=nums[ind]) take = subsetsum(ind-1, target-nums[ind], nums, dp);

   return dp[ind][target] = take || not_take;
}


// bool subsetSumToK(int n, int k, vector<int> &arr) {

//     vector<bool> prev(k + 1, false);

//     prev[0] = true;

//     if (arr[0] <= k) {
//         prev[arr[0]] = true;
//     }

//     for (int ind = 1; ind < n; ind++) {

//         vector<bool> cur(k + 1, false);

//         cur[0] = true;

//         for (int target = 1; target <= k; target++) {
     
//             bool notTaken = prev[target];

//             bool taken = false;
//             if (arr[ind] <= target) {
//                 taken = prev[target - arr[ind]];
//             }
//             cur[target] = notTaken || taken;
//         }

//         prev = cur;
//     }

//     return prev[k];
// }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum  =0;
        for(int i =0; i<n; i++){
            totalsum += nums[i];

        }
        if(totalsum%2) return false;
        int target = totalsum/2;
vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
//bool subsetSumToK(int n, int k, vector<int> &arr) {
        //return subsetSumToK(n, target, nums);
        return subsetsum(n-1, target, nums, dp);
    }
};