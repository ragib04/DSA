class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        //step 1 
        for(int i = n-1 ; i>0; i--){
           
                if(nums[i]>nums[i-1]){
                pivot = i-1;
                break;
                }
            
        }
        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
           
            for(int j = n-1; j>pivot; j--){
                if(nums[j]> nums[pivot]){
                    swap(nums[pivot], nums[j]);
                    break;
                }
            }
        

        reverse(nums.begin()+pivot+1, nums.end());
    }
};