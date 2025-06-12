class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxjump = nums.size()-1;
        for(int i = nums.size()-2; i>=0; i--){
            if(maxjump<=i+nums[i]) maxjump = i;

        }
return (maxjump == 0)? true : false;
    }
};