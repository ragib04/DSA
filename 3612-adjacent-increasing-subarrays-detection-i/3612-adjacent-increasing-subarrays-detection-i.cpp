class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int currRun = 1, prevRun = 0;

        for(int i = 1; i<n; i++){
            if(nums[i]>nums[i-1]) currRun++;
            else{
                prevRun = currRun;
                currRun = 1;

            }

            if(currRun/2 >= k) return true;

            if(min(currRun, prevRun)>=k) return true;
        }
        return false;
    }
};