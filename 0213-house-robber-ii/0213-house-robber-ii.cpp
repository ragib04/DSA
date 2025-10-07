class Solution {
public:

int robber(vector<int> &nums){
    int n = nums.size();

    vector<int> dp(n+1, 0);
    dp[0] = nums[0];
    for(int i = 1; i<n; i++){
        int pick = nums[i];
        if(i>1) pick += dp[i-2];
        int not_pick = dp[i-1];

        dp[i] = max(pick, not_pick);
    }
    return dp[n-1];
    
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