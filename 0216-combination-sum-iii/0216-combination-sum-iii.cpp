class Solution {
public:

void func(int i, int k, int sum, int n, vector<int> &subset, vector<vector<int>>& ans){
    if(sum>n) return;
    if(k==0){

    if(sum == n){
        ans.push_back(subset);
    }
    return;
    }
    if(i == 10) return;
    //pick
    sum += i;
    subset.push_back(i);
    func(i+1,k-1,sum,n,subset,ans);
    sum -= i;
    subset.pop_back();

    //ignore
    func(i+1,k,sum,n,subset,ans);
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subset;
        vector<vector<int>> ans;
        func(1,k,0,n, subset, ans);
        return ans;
    }
};