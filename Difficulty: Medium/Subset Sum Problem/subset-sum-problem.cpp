//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  bool f(vector<int> &arr, int ind, int sum, vector<vector<int>> &dp){
      if(sum == 0) return true;
      if(ind == 0) return (arr[ind] == sum);
      
      if(dp[ind][sum] != -1) return dp[ind][sum];
      
      bool not_take = f(arr, ind-1, sum, dp);
      bool take = false;
     if(sum>=arr[ind]) {
         take = f(arr, ind-1, sum-arr[ind], dp);
     }
      
      return dp[ind][sum] = take | not_take;
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        return f(arr, n-1, sum, dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends