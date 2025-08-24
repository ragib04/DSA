class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> dp;
int cnt = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1) cnt++;
            else{
                dp.push_back(cnt);
                cnt = 0;
            }

        }
        dp.push_back(cnt);
        int maxi = 0;
        if(dp.size() == 1) return dp[0] - 1;
        for(int i = 0; i<dp.size()-1; i++){
            maxi = max(maxi, dp[i]+dp[i+1]);
        }
        return maxi;
       
//        int left = 0; // 1 2 3
//         int res = 0; //  0 1  2  3   4  5 
//         int zeros = 0; // 1 2 1 2
//        for(int right = 0; right<nums.size(); right++){
//         if(nums[right] == 0) zeros++;
//        while(zeros>1){
//         if(nums[left] == 0) zeros--;
// left++;
//        }
//        res = max(res, right-left);
//         }
//         return res;
    }
};