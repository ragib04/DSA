class Solution {

public:

void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> path,int i){
    if(i>=nums.size()){
        ans.push_back(path);
        return;
    }
    //skip
    solve(nums, ans, path, i+1);
    path.push_back(nums[i]);
    solve(nums, ans, path, i+1);
}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(nums, ans, path, 0);
        return ans;
    }
};