class Solution {
public:
void solve(int ind, vector<int> &nums, vector<vector<int>> &ans, vector<int> & path, int n){
    ans.push_back(path);
       
    for(int i = ind; i<n; i++){

        if(i > ind && nums[i] == nums[i-1]) continue;
        path.push_back(nums[i]);
        solve(i+1, nums, ans, path, n);
        path.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        solve(0, nums, ans, ds, n);
        return ans;
    }
};