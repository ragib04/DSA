class Solution {
public:
    void sortColors(vector<int>& nums) {
        
       int s = 0, curr = 0, e = nums.size()-1;
       while(curr<=e){
        if(nums[curr] == 0){
            swap(nums[curr], nums[s]);
            s++;
            curr++;
        }
        else{
            if(nums[curr] == 2){
                swap(nums[curr], nums[e]);
                e--;
            }
            else{
                curr++;
            }
        }
       }
    }
};