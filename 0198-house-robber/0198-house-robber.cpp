class Solution {
public:
int robed(int ind, vector<int> &nums, vector<int> &dp){
    if(ind == 0) return nums[ind];
    if(ind<0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int pick = nums[ind] + robed(ind-2, nums, dp);
    int not_pick = robed(ind-1, nums, dp);

    dp[ind] = max(pick, not_pick);
    return dp[ind];
}
    int rob(vector<int>& nums) {
        int n= nums.size();
        //vector<int> dp(n+1, -1);
        vector<int> dp(n+1);
        //return robed(n-1, nums, dp);
        dp[0] = nums[0];
        
        for(int i= 1; i<n; i++){
            int pick = nums[i];
            if(i>1) pick = pick+dp[i-2];
            int not_pick = dp[i-1];

            dp[i] = max(pick, not_pick);
        }
        return dp[n-1];
    }
};