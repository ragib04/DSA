class Solution {
public:
void permute(vector<int> &nums, set<vector<int>> &ans, int ind){
    if(ind == nums.size()) ans.insert(nums);

    for(int i = ind; i<nums.size(); i++){
        swap(nums[i], nums[ind]);
        permute(nums, ans, ind+1);
        swap(nums[i], nums[ind]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        permute(nums, ans, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

/*
class Solution {
public:

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;
        ans.insert(nums);
        while (true) {
            int ind = -1;

            for (int i = n - 2; i >= 0; i--) {
                if (nums[i] < nums[i + 1]) {
                    ind = i;
                    break;
                }
            }
            if (ind == -1)
                break;
            for (int i = n - 1; i >= 0; i--) {
                if (nums[i] > nums[ind]) {
                    swap(nums[i], nums[ind]);
                    break;
                }
            }
            reverse(nums.begin() + ind + 1, nums.end());
            ans.insert(nums);
        }
        
        
    }
};
*/