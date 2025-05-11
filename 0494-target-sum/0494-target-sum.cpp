class Solution {
public:
int func(int ind, int k, vector<int> &arr, vector<vector<int>> &dp){
    if(ind == 0){
        if(k == 0 && arr[0] == 0) return 2;
        if(k == 0 ||k == arr[0] ) return 1;

        return 0;
    }
    if(dp[ind][k] != -1) return dp[ind][k];
    int not_take = func(ind-1, k, arr, dp);
    int take = 0;
    if(arr[ind] <= k) take = func(ind-1, k-arr[ind], arr, dp);

    return dp[ind][k] = (take+not_take);

}

int findways(int n, vector<int> &nums, int k){
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return func(n-1, k, nums, dp);
}

int countpartitions(int n, int target, vector<int> &nums){
    int totalsum = 0;
    for(auto &it: nums) totalsum += it;

    if(totalsum-target < 0 || (totalsum-target)%2) return 0;
    return findways(n, nums, (totalsum-target)/2);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        return countpartitions(n, target, nums);

    }
};