class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        int x = nums[0];
        int cnt = 1;
        int ans =0;
        for(int i = 1; i<n; i++){
            if(nums[i] == x) continue;
            if(x+1 == nums[i]){
                x = nums[i];
                cnt++;
            }
            else{
                ans = max(ans, cnt);
                cnt = 1;
                x = nums[i];
            }

        }
        ans = max(ans, cnt);
        return ans;
    }
};