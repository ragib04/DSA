class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int cnt_zero = 0;
        int i = 0;
        for(int j = 0; j<n; j++){
            if (nums[j] == 0)
                cnt_zero++;
            if(cnt_zero > k) {
                if (nums[i] == 0)
                    cnt_zero--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }
       
return ans;
    }
};