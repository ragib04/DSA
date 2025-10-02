class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1) / 2;
        int actualsum = 0;
        for(auto num:nums){
            actualsum += num;
        }
        return sum-actualsum;
    }
};