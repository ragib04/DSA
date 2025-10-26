class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int ans = 0;// 1 2
        long curr = 0; // 1 2 // 6 5
        
        for (int right = 0; right < nums.size(); right++) {
            long target = nums[right]; // 1 2 // 4
            curr += target; 
            
            while ((right - left + 1) * target - curr > k) {
                curr -= nums[left];
                left++;
            }
            
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};