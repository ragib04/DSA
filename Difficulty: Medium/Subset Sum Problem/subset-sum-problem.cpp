//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  //MEMOIZATION
//   bool f(vector<int> &arr, int ind, int sum, vector<vector<int>> &dp){
//       if(sum == 0) return true;
//       if(ind == 0) return (arr[ind] == sum);
      
//       if(dp[ind][sum] != -1) return dp[ind][sum];
      
//       bool not_take = f(arr, ind-1, sum, dp);
//       bool take = false;
//      if(sum>=arr[ind]) {
//          take = f(arr, ind-1, sum-arr[ind], dp);
//      }
      
//       return dp[ind][sum] = take | not_take;
//   }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        // return f(arr, n-1, sum, dp);
        
       // Tabulation
       /* 
        vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));
        
        for(int i =0; i<n; i++){
            dp[i][0] = true;
        }
        dp[0][arr[0]] = true;
        
        for(int ind = 1; ind<n; ind++){
            for(int target = 1; target<=sum; target++){
                bool not_take = dp[ind-1][target];
                bool take = false;
                if(arr[ind]<=target) take = dp[ind-1][target-arr[ind]];
                
                
                dp[ind][target] = take || not_take;
            }
        }
        return dp[n-1][sum];
        */
        
 //space optimization       
vector<bool> prev(sum+1, 0), curr(sum+1, 0);
        
        prev[0] = curr[0] = true;
       prev[arr[0]] = true;
        
        for(int ind = 1; ind<n; ind++){
            for(int target = 1; target<=sum; target++){
                bool not_take = prev[target];
                bool take = false;
                if(arr[ind]<=target) take = prev[target-arr[ind]];
                
                
                curr[target] = take || not_take;
            }
            prev = curr;
        }
        return prev[sum];
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
