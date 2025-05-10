class Solution {
public:

int func(int ind, int k, vector<int> &arr, vector<vector<int>> &dp){
	if(ind == 0){
		if(k == 0 && arr[0] == 0) return 2;
		if(k == 0 || k == arr[0]) return 1;

		return 0;
	}
	if(dp[ind][k] != -1) return dp[ind][k];

	int not_take = func(ind-1, k, arr, dp);
	int take  = 0;
	if(arr[ind] <= k) take = func(ind-1, k- arr[ind], arr, dp);

	return dp[ind][k] = (not_take + take);
}
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, -1));
	return func(n-1, k, arr, dp);
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totalsum = 0;
     for(auto &it: arr) totalsum += it;

     if(totalsum - d <0 || (totalsum-d)%2) return 0;
     return findWays(arr, (totalsum-d)/2);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        return countPartitions(n, target, nums);
    }
};