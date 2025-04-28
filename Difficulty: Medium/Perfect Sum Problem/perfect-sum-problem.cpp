//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int cntsubset(int ind, vector<int> &arr, int target, vector<vector<int>> &dp)
  {
        if(ind == 0){
          if(target == 0 && arr[0] == 0) return 2;
          if(target == 0 || arr[0] == target) return 1;
          return 0;
      }
      
      if(dp[ind][target] != -1) return dp[ind][target];
      
      int not_pick = cntsubset(ind-1, arr, target, dp);
      int pic = 0;
      if(arr[ind]<=target) pic = cntsubset(ind-1,  arr, (target-arr[ind]), dp);
      
      return dp[ind][target] = pic + not_pick;
  }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return cntsubset(n-1, arr, target, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends