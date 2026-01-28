class Solution {
public:
void solve(int ind, vector<int> &nums, int k, vector<vector<int>> &ans, vector<int> &path, int n){
    if(k==0){
        ans.push_back(path);
        return;
    }
    for(int i = ind; i<n; i++){
        if(i>ind && nums[i] == nums[i-1]) continue;
        if(nums[i]>k) break;
        path.push_back(nums[i]);
        solve(i+1, nums, k-nums[i], ans, path,n);
        path.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        int n = candidates.size();
        solve(0, candidates, target, ans, path, n);
        return ans;
    }
};