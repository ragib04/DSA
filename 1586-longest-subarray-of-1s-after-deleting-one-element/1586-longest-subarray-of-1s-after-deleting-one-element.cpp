class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0; // 1 2 3
        int res = 0; //  0 1  2  3   4  5 
        int zeros = 0; // 1 2 1 2
       
       for(int right = 0; right<nums.size(); right++){
        if(nums[right] == 0) zeros++;
       while(zeros>1){
        if(nums[left] == 0) zeros--;
left++;
       }
       res = max(res, right-left);
        }
        return res;
    }
};