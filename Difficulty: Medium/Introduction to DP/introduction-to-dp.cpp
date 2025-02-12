//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  long long int mod = 1000000007;
  long long int fib(int n, vector<long long int> &dp){
      if(n == 0 || n==1){
          return n;
      }
      if(dp[n] != -1) return dp[n];
      
      dp[n] = ((fib(n-1, dp))%mod+(fib(n-2, dp))%mod)%mod;
      
      return dp[n];
  }
    long long int topDown(int n) {
        // code here
        vector<long long int> dp(n+1,-1);
        return fib(n, dp);
    }
    long long int bottomUp(int n) {
        // code here
        vector<long long int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(long long int i = 2; i<=n; i++){
            dp[i] = ((dp[i-1]%mod)+(dp[i-2]%mod))%mod;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends