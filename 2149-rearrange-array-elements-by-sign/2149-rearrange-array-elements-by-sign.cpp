class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pi = 0, ni = 1;
        vector<int> ans(n);
        for(int i = 0; i<n; i++){
            if(nums[i]>=0){
                ans[pi] = nums[i];
                pi += 2;
            }
            else{
                ans[ni] = nums[i];
                ni += 2;
            }
        }
        return ans;
    }
};