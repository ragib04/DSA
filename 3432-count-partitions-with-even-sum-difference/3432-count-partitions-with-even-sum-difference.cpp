class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum= 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
        }
        //is sum is even the ans is n-1 otherwise 0;
        if(sum%2 == 0) return n-1;
        return 0;

        // int ans = 0;
        // int curr_sum = 0;
        // for(int i = 0; i<nums.size()-1; i++){
        //     curr_sum += nums[i];
        //     int partition = sum - curr_sum;
        //     if(abs(curr_sum - partition)%2 == 0) ans++;
        // }
        // return ans;
    }
};