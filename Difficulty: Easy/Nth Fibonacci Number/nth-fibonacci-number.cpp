//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
 
 
// recursive------->
    int nthFibonacci(int n) {
        // code here
        vector<int> dp(n+1);
       dp[0] = 0;
       dp[1] = 1;
       for(int i = 2; i<=n; i++){
           dp[i] = dp[i-1]+dp[i-2];
       }
        return dp[n];
        
        
    }


  //dp-------->
  int fib(int n, vector<int> &dp){
      //base case
      if(n==0 || n==1) return n;
      //step 3 check memorize vale
      if(dp[n] != -1) return dp[n];
      //step 2 store prev value
      dp[n] = fib(n-1, dp)+ fib(n-2, dp);
      return dp[n];
  }
    int nthFibonacci(int n) {
        // code here
        //step 1 memorize
        vector<int> dp(n+1,-1);
        return fib(n, dp);
        
        
    }


};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
