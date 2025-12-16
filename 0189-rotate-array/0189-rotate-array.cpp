class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        // vector<int> temp(n);
        // // temp[(i+k)%n] = nums[i];
        // for(int i = 0; i<n;i++){
        //     temp[(i+k)%n] = nums[i];
        // }
        // nums = temp;
        // [1,2,3,4,5,6,7]
        k  = k%n;
        reverse(nums.begin(), nums.end()); // [7,6,5,4,3,2,1]
        reverse(nums.begin(), nums.begin()+k);//[5,6,7,4,3,2,1]
        reverse(nums.begin()+k, nums.end()); // [5,6,7,1,2,3,4]
    }
};