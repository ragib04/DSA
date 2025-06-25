class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];
        int n= nums.size();
        int s = 1;
        int e = n-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid]<min){
                min = nums[mid];
                e = mid-1;
            }
            else s = mid+1;
        }
        return min;
        
    }
};