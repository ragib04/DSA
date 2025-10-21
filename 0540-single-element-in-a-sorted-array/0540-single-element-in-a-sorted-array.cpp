class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 1, e = n-2;
        if(n == 1) return nums[0];
        //bpundary condition
        if(nums[s] != nums[s-1]) return nums[s-1];
        if(nums[e] != nums[e+1]) return nums[e+1];
        while(s<=e){

            int mid = (s+e)/2;
            if((nums[mid] != nums[mid+1]) && (nums[mid] != nums[mid-1])){
                return nums[mid];

            }
            if((mid%2 == 1 && nums[mid] == nums[mid-1]) || (mid%2 == 0 && nums[mid] == nums[mid+1])){
                s = mid+1;
            }
            else{ e = mid-1;}

        }
        return 0;
    }
};