class Solution {
  public:
  int func(int i, vector<int> &arr, int k, vector<int> &dp){
      if(i == 0) return 0;
      int mmsteps = INT_MAX;
      for(int j = 1; j<=k; j++){
          if(i-j>=0){
              int jump = func(i-j, arr, k, dp)+ abs(arr[i] - arr[i-j]);
              
              mmsteps = min(jump, mmsteps);
          }
         
      }
      return dp[i] = mmsteps;
  }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> dp(n+1);
        
        dp[0] = 0;
        for(int i = 1; i<n; i++){
            int mmsteps = INT_MAX;
            for(int j = 1; j<=k; j++){
                if(i-j>=0) {
                    int jump = dp[i-j]+abs(arr[i]- arr[i-j]);
                    
                    mmsteps = min(mmsteps, jump);
                }
            }
            dp[i] = mmsteps;
        }
       // return func(n-1, arr, k, dp);
       return dp[n-1];
    }
};