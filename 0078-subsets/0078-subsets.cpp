class Solution {
public:
void helper(vector<int> &nums, int i, int n, vector<int> &path, vector<vector<int>> &ans){
    if(i == n){
        ans.push_back(path);
        return;
    }
    path.push_back(nums[i]);
    helper(nums, i+1, n, path, ans);
    path.pop_back();
    helper(nums, i+1, n, path, ans);
    
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = nums.size();
        helper(nums, 0, n, path, ans);
        return ans;
    }
};