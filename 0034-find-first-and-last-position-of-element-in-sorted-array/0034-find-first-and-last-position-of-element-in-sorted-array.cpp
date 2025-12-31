class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return {-1, -1};
        if(n == 1 && target == nums[0]) return {0, 0};
        int s = 0, e = n-1;
        
        vector<int> ans(2, -1);
        int lower = -1, greater = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            
            if(nums[mid] >= target){

                if(nums[mid] == target) lower = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        s = 0, e = n-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid]<=target){
                if(nums[mid] == target) greater = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
        if(lower != -1 && greater != -1){
            ans[0] = lower;
            ans[1] = greater;
        }

        return ans;
    }
};