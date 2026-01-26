class Solution {
  public:
 
  bool func(int i, int n, int sum, vector<int> &arr){
      if(sum == 0) return sum == 0;
      if(i == n) return false;
      if(arr[i]<=sum) if(func(i+1, n, sum-arr[i], arr)) return true;;
      if(func(i+1, n, sum, arr)) return true;
  }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        bool flag= func(0, n, k, arr);
        return flag;
        
    }
};