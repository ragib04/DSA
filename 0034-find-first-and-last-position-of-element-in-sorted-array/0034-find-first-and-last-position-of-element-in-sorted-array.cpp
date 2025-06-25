class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int starting = -1;
        int ending = -1;
        for(int i = 0; i<n; i++){
            if(nums[i] == target){
                starting = i;
                break;
            }
        }
        for(int i = n-1; i>= 0; i--){
            if(nums[i] == target){
                ending = i;
                break;
            }
            
        }
        return{starting,ending};

    }
};