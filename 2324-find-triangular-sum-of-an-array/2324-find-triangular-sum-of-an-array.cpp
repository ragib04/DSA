class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        
        while(n > 1){
            vector<int> newArr;
        for(int i = 0; i<n-1; i++){
            newArr.push_back((nums[i]+nums[i+1])%10);

        }
            nums = newArr;
            n--;
        }
        return nums[0];
        
    }
};