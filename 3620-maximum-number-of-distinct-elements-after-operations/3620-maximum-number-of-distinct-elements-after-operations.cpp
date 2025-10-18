class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int prev = -1e9;

        for(int i = 0; i<n; i++){
            int left_ele = max(nums[i]-k, prev+1);
            if(left_ele<=nums[i]+k){
                prev = left_ele;
                ans++;
            }
        }
        return ans;
    }
};