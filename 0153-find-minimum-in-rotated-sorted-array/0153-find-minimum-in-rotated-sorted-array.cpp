class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = nums[0];
        int s = 0, e = nums.size()-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]<mini){
                mini = nums[mid];
                e = mid-1;
            }
            else s = mid+1;
        }
        return mini;
    }
};