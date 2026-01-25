class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int mini = INT_MAX;
        int n = nums.size();
        if(n == 1 && k == 1) return 0;

        sort(nums.begin(), nums.end());
        int i = 0, j= k-1;
        while(j<n){
            int diff = nums[j]-nums[i];
            mini = min(mini, diff);
            i++;j++;
        }
        return mini;

    }
};