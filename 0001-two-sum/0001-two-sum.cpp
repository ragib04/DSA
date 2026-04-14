class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
vector<int> arr(2);
int n = nums.size();
        for(int i = 0; i<n; i++){
            int sum = nums[i];
            for(int j = i+1; j<n; j++){
                if(sum + nums[j] == target) {
                    arr[0] = i;
                    arr[1] = j;
                    break;
                }
            }
        }
        return arr;
    }
};