class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid]>=nums[s]){ // it means from s to mid arr is sorted
                if(nums[s]<=target && nums[mid]>target) e = mid-1; // it means ans is in between s and m
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
/*
   0 1 2 3 4 5 6
//[4,5,6,7,0,1,2] target= 2
mid = 3
*/