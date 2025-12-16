class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int i = 0;
       for(int j = 1; j<nums.size(); j++){
        if(nums[i] == 0 && nums[j] != 0){
            nums[i] = nums[j];
            nums[j] = 0;
            i++;
        }
        else{
            if(nums[i] != 0) i++;
        }
       }
    }
};