class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      // int i = 0, j = 0;
       int n = nums.size();
       
       int ans = INT_MIN;
       int sum = 0;
    for(int i = 0; i<n; i++){
        if(sum<0) sum = 0;
        sum += nums[i];
        if(sum > ans) ans= sum;
        
    }
    return ans;
    }
};