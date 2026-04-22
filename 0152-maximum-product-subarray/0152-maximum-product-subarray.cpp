class Solution {
public:

/*
The key to solving this problem is understanding how negative numbers and zero affect the product of a subarray. A single negative number can turn the smallest product into the largest if multiplied correctly, so we must track both the maximum and minimum products at each step.
*/
    int maxProduct(vector<int>& nums) {
        
int n = nums.size();
int currmax = nums[0];
int currmin = nums[0];
int ans = nums[0];

        for(int i = 1; i<n; i++){
           if(nums[i] <0) swap(currmax, currmin);

           currmax= max(nums[i], currmax*nums[i]);
           currmin = min(nums[i], currmin*nums[i]);

           ans = max(currmax, ans);
            
            
        }
        return ans;
    }
};