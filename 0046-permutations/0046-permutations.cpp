class Solution {
public:
vector<vector<int>> res;
int n;
unordered_set<int> st;
void solve(vector<int> &nums, vector<int> &temp){
    if(temp.size() == n){
        res.push_back(temp);
        return;
    }
    for(int i =0; i<n; i++){
        if(st.find(nums[i]) == st.end()){
            st.insert(nums[i]);
            temp.push_back(nums[i]);
            solve(nums, temp);
            temp.pop_back();
            st.erase(nums[i]);
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        solve(nums, temp);
        return res;
    }
};

/*
class Solution {
public:

void recpermute(int ind, vector<int> &nums, vector<vector<int> > &ans){
    if(ind == nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i = ind; i< nums.size(); i++){
        swap(nums[ind], nums[i]);
        recpermute(ind+1, nums, ans);
        swap(nums[ind], nums[i]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recpermute(0, nums, ans);
        return ans;
    }
};
*/