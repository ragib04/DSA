class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0; // 4
        int res = 0;
        int zeros = 0;

        for(int right = 0; right<nums.size(); right++){
            if(nums[right] == 0) {
                zeros++;
                while(zeros>k){
                    if(nums[left] == 0) zeros--;
                    left++;
                }
            }
            
            res = max(res, right-left+1);
            
        }
        return res;


    }
};