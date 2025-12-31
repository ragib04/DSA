class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid]>=nums[s]){
                if(nums[s]<=target && nums[mid]>target) e = mid-1;
                else s = mid+1;
            }
            else{
                if(nums[mid]<target && target<=nums[e]) s = mid+1;
                else e = mid-1;
            }
        }
        return -1;
    }
};