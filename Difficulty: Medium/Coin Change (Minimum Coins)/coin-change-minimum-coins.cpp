//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
  
 
   
        // Your code goes here
     int minCoins(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<int> dp(sum + 1, INT_MAX);  
        dp[0] = 0;  

        for (int i = 1; i <= sum; i++) {
            for (int j = 0; j < n; j++) {
                if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }

        return (dp[sum] == INT_MAX) ? -1 : dp[sum];  
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends