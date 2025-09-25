class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int pre[] = new int[n];
        int suff[] = new int[n];
        pre[0] = 1; //[1 1 2 6]
        suff[n - 1] = 1;    //[24 12 4 1]
        
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] * nums[i - 1];
        }
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] * nums[i + 1];
        }
        
        int ans[] = new int[n];     // [24 12 8 6]
        for(int i = 0; i < n; i++) {
            ans[i] = pre[i] * suff[i];
        }
        return ans;
    }
}