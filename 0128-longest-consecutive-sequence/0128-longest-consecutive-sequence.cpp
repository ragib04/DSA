class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        sort(nums.begin(), nums.end());
        int cnt = 1; int ans = 1;
        for(int i = 1; i<n; i++){
            int x = nums[i-1];
            if(nums[i] == x) continue;
            if(x == nums[i]-1) cnt++;
            else {
                ans  = max(cnt, ans);
                cnt = 1;
            }
        }
        return max(ans, cnt);
    }
};