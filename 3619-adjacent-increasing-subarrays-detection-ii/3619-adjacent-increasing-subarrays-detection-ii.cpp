class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int currRun = 1, prevRun = 0;

        int maxi = 1;
        for(int i = 1; i<n; i++){
            if(nums[i]>nums[i-1]){
                currRun++;
            }
            else{
                prevRun = currRun;
                currRun = 1;
            }

           
                maxi = max(maxi, currRun/2);
            maxi = max(maxi, min(currRun, prevRun));
        }
        return maxi;
    }
};