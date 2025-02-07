class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int near = 0, far = 0, jump = 0;
        while(far < n-1){
            int farthest = 0;
            for(int  i = near; i<=far; i++){
                farthest = max(farthest, i+nums[i]);
            }
            near = far+1;
            far = farthest;
            jump++;
        }
        return jump;
    }
};