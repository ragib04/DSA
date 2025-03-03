//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  /*
   int solve(vector<int> &wt, vector<int> &val, int idx, int capacity){
        if(idx == 0){
            if(wt[idx]<= capacity){
                return val[0];
            }
            else return 0;
        }
        
        int include = 0;
        if(wt[idx]<=capacity) include= val[idx]+ solve(wt, val, idx-1, capacity - wt[idx]);
        
        int exclude = solve(wt, val, idx-1, capacity);
        
        int ans = max(include, exclude);
        return ans;
    }
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        return solve(wt, val, n-1, capacity);
    }
  */
  
  
  
   int solveMem(vector<int> &wt, vector<int> &val, int idx, int capacity, vector<vector<int>>&dp){
        if(idx == 0){
            if(wt[idx]<= capacity){
                return val[0];
            }
            else return 0;
        }
        if(dp[idx][capacity] != -1) return dp[idx][capacity];
        
        int include = 0;
        if(wt[idx]<=capacity) include= val[idx]+ solveMem(wt, val, idx-1, capacity - wt[idx], dp);
        
        int exclude = solveMem(wt, val, idx-1, capacity, dp);
        
       dp[idx][capacity] = max(include, exclude);
        return dp[idx][capacity];
    }
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int> (capacity+1,-1));
        return solveMem(wt, val, n-1, capacity, dp);
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends